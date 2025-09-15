//From <https://code.ptit.edu.vn/student/question/DSA11019> 



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
node* build_tree(vector<int>& pre_order, int min_val, int max_val){
    if(pre_order.empty()) return NULL;
    int root_val = pre_order[0];
    if(root_val < min_val || root_val > max_val) return NULL;
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
        vector<int> pre_order;
        for(int i = 0; i <n ; i++){
            int x; cin >> x;
            pre_order.push_back(x);
        }
        int tmp = 0;
        node* root = build_tree(pre_order, INT_MIN, INT_MAX);
        post_order(root);
        cout << endl;
    }
}
