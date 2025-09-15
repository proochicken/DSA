//From <https://code.ptit.edu.vn/student/question/DSA11025> 

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
node* build_tree(vector<int>& v, int min_val, int max_val){
    if(v.empty()) return NULL;
    int root_pos = v.size() / 2;
    if(v.size() % 2 == 0) root_pos -= 1;
    
    int root_val = v[root_pos];
    if(root_val < min_val || root_val > max_val) return NULL;
    node* root = new node(root_val);
    vector<int> l, r;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == root_val) continue;
        if(v[i] < root_val) l.push_back(v[i]);
        else r.push_back(v[i]);
    }
    root->left = build_tree(l, min_val, root_val - 1);
    root->right = build_tree(r, root_val + 1, max_val);
    return root;
}
void pre_order(node* root){
    if(root == NULL) return;
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
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
        node* root = build_tree(v, INT_MIN, INT_MAX);
        pre_order(root);
        cout << endl;
    }
}
