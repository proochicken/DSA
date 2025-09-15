//From <https://code.ptit.edu.vn/student/question/DSA11021> 



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
node* build_tree(vector<int> pre_order, int min_val, int max_val){
    if(pre_order.empty()) return NULL;
    int root_val = pre_order[0];
    if(root_val < min_val || root_val > max_val){
        return NULL;
    }
    node* root = new node(root_val);
    vector<int> l, r;
    for(int i = 1; i < pre_order.size(); i++){
        if(pre_order[i] < root_val) l.push_back(pre_order[i]);
        else r.push_back(pre_order[i]);
    }
    root->left = build_tree(l, min_val, root_val - 1);
    root->right = build_tree(r, root_val + 1, max_val);
    return root;
}
void is_leaf(node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        cout << root->val << " ";
    }
    is_leaf(root->left);
    is_leaf(root->right);
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> pre;
        for(int i = 0; i <n ; i++){
            int x; cin >> x;
            pre.push_back(x);
        }
        node* root = build_tree(pre, INT_MIN, INT_MAX);
        is_leaf(root);
        cout << endl;
    }
}
