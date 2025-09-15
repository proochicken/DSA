//From <https://code.ptit.edu.vn/student/question/DSA11017> 



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
node* build_tree(vector<int>& v, int& idx, int min_val, int max_val){
    if(idx >= v.size()) return NULL;
    int val_root = v[idx];
    if(val_root < min_val || val_root > max_val){
        return NULL;
    }
    node* root = new node(v[idx]);
    idx++;
    root->left = build_tree(v, idx, min_val, val_root - 1);
    root->right = build_tree(v, idx, val_root + 1, max_val);
    return root;
}
void post_order(node* root){
    if(root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int tmp = 0;
        node* root = build_tree(v, tmp, INT_MIN, INT_MAX);
        post_order(root); cout << endl;
    }
}
