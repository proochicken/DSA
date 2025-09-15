//From <https://code.ptit.edu.vn/student/question/DSA11005> 



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
unordered_map<int, int> idx_in_order;
node* build_tree(vector<int>& in_order, int start_in, int end_in, vector<int>& level_order, int start_level, int end_level){
    if(start_in > end_in || start_level > end_level) return NULL;
    int root_val = level_order[start_level];
    int root_pos = idx_in_order[root_val];
    node* root = new node(root_val);
    vector<int> l, r;
    for(int i = start_level + 1; i <= end_level; i++){
        int x = level_order[i];
        int pos = idx_in_order[x];
        if(pos < root_pos) l.push_back(x);
        else if(pos == root_pos) continue;
        else r.push_back(x);
    }
    root->left = build_tree(in_order, start_in, root_pos - 1, l, start_level, l.size() - 1);
    root->right = build_tree(in_order, root_pos + 1, end_in, r, start_level, r.size() - 1);
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
        vector<int> in_order(n), level_order(n);
        for(int i = 0; i < n; i++){
            cin >> in_order[i];
            idx_in_order[in_order[i]] = i;
        }
        for(int i = 0; i < n; i++){
            cin >> level_order[i];
        }
        node* root = build_tree(in_order, 0, n - 1, level_order, 0, n - 1);
        post_order(root);
        cout << endl;
    }
}
