//From <https://code.ptit.edu.vn/student/question/DSA11016> 



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
void make_root(node* root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}
void insert_node(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        make_root(root, u, v, c);
    }
    else{
        insert_node(root->left, u, v, c);
        insert_node(root->right, u, v, c);
    }
}
void get_in_order(node* root, vector<int>& vals){
    if(root == NULL) return;
    get_in_order(root->left, vals);
    vals.push_back(root->val);
    get_in_order(root->right, vals);
}
void assign_node(node* root, vector<int>& vals, int& idx){
    if(root == NULL) return;
    assign_node(root->left, vals, idx);
    root->val = vals[idx++];
    assign_node(root->right, vals, idx);
}
void in_order(node* root){
    if(root == NULL) return;
    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}
int main(){
    int t; cin >> t;
    while(t--){
        node* root = NULL;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int u, v; char c;
            cin >> u >> v >> c;
            if(root == NULL){
                root = new node(u);
                make_root(root, u, v, c);
            }
            else insert_node(root, u, v, c);
        }
        vector<int> vals;
        int tmp = 0;
        get_in_order(root, vals);
        sort(vals.begin(), vals.end());
        assign_node(root, vals, tmp);
        in_order(root);
        cout << endl;
    }
}
