//From <https://code.ptit.edu.vn/student/question/DSA11015> 



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
int sum_leaf(node* root, int& res){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->val;
    int sum_left = sum_leaf(root->left, res);
    int sum_right = sum_leaf(root->right, res);
    if(root->left != NULL && root->right != NULL){
        res = max(res, sum_left + sum_right + root->val);
        return max(sum_left, sum_right) + root->val;
    }
    if(root->left == NULL) return sum_right + root->val;
    else return sum_left + root->val;
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
            else{
                insert_node(root, u, v, c);
            }
        }
        int tmp = INT_MIN;
        sum_leaf(root, tmp);
        cout  << tmp << endl;
    }
}
