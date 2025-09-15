//From <https://code.ptit.edu.vn/student/question/DSA11006> 



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
void spiral_order(node* root){
    if(root == NULL) return;
    stack<node*> st1, st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            node* x = st1.top(); st1.pop();
            cout << x->val << " ";
            if(x->right != NULL){
                st2.push(x->right);
            }
            if(x->left != NULL){
                st2.push(x->left);
            }
        }
        while(!st2.empty()){
            node* x = st2.top(); st2.pop();
            cout << x->val << " ";
            if(x->left != NULL){
                st1.push(x->left);
            }
            if(x->right != NULL){
                st1.push(x->right);
            }
        }
    }
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
        spiral_order(root);
        cout << endl;
    }
}
