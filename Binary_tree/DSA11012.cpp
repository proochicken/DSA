//From <https://code.ptit.edu.vn/student/question/DSA11012> 



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
bool compare(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1->val != root2->val){
        return false;
    }
    if(root1 == NULL || root2 == NULL) return false;
    return compare(root1->left, root2->left) && compare(root1->right, root2->right);
}
int main(){
    int t; cin >> t;
    while(t--){
        node* root1 = NULL;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int u, v; char c;
            cin >> u >> v >> c;
            if(root1 == NULL){
                root1 = new node(u);
                make_root(root1, u, v, c);
            }
            else{
                insert_node(root1, u, v, c);
            }
        }
        node* root2 = NULL;
        int m; cin >> m;
        for(int i = 0; i < m; i++){
            int u, v; char c;
            cin >> u >> v >> c;
            if(root2 == NULL){
                root2 = new node(u);
                make_root(root2, u, v, c);
            }
            else{
                insert_node(root2, u, v, c);
            }
        }
        
        if(compare(root1, root2)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
