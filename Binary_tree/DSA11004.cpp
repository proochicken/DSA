//From <https://code.ptit.edu.vn/student/question/DSA11004> 



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
void insert_root(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        make_root(root, u, v, c);
    }
    else{
        insert_root(root->left, u, v, c);
        insert_root(root->right, u, v, c);
    }
}
void level_order(node* root){
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* top = q.front(); q.pop();
        cout << top->val << " ";
        if(top->left != NULL){
            q.push(top->left);
        }
        if(top->right != NULL){
            q.push(top->right);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        node* root = NULL;
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            int u, v; char c;
            cin >> u >> v >> c;
            if(root == NULL){
                root = new node(u);
                make_root(root, u, v, c);
            }
            else{
                insert_root(root, u, v, c);
            }
        }
        level_order(root);
        cout << endl;
    }
}
