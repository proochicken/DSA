//From <https://code.ptit.edu.vn/student/question/DSA11026> 

#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};
node* build_tree(vector<int>& v, int n){
    int root_pos;
    if(n % 2 == 0) root_pos = n / 2 - 1;
    else root_pos = n / 2;
    if(root_pos < 0) return NULL;
    node* root = new node(v[root_pos]);
    vector<int> l, r;
    for(int i = 0; i < n; i++){
        if(i == root_pos) continue;
        if(i < root_pos) l.push_back(v[i]);
        else r.push_back(v[i]);
    }
    root->left = build_tree(l, root_pos);
    root->right = build_tree(r, n - root_pos - 1);
    return root;
}
void pre_order(node* root){
    if(root == NULL) return;
    pre_order(root->left);
    pre_order(root->right);
    cout << root->val << " ";
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        node* root = build_tree(v, n);
        pre_order(root);
        cout << endl;
    }
}
