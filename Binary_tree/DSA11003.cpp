//From <https://code.ptit.edu.vn/student/question/DSA11003> 



#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left; 
    node* right;
    node(int s){
        val = s;
        left = right = NULL;
    }
};
unordered_map<int, int> in_order_map;
node* build_tree(vector<int>& in_order, int start_in, int end_in, vector<int>& pre_order, int start_pre, int end_pre){
    if(start_in > end_in || start_pre > end_pre) return NULL;
    node* root = new node(pre_order[start_pre]);
    int val_root = pre_order[start_pre];
    int val_pos = in_order_map[val_root];
    int sz = val_pos - start_in;
    root->left = build_tree(in_order, start_in, val_pos - 1, pre_order, start_pre + 1, start_pre + sz);
    root->right = build_tree(in_order, val_pos + 1, end_in, pre_order, start_pre + sz + 1, end_pre);
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
        vector<int> in_order(n), pre_order(n);
        for(int i = 0; i < n; i++){
            cin >> in_order[i];
            in_order_map[in_order[i]] = i;
        }
        for(int i = 0; i < n; i++){
            cin >> pre_order[i];
        }
        node* root = build_tree(in_order, 0, n - 1, pre_order, 0, n - 1);
        post_order(root); cout << endl;
    }
}
