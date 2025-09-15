//From <https://code.ptit.edu.vn/student/question/DSA11010> 



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
unordered_set<int> se;
void check_1(node* root, int depth){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        se.insert(depth);
    }
    if(root->left != NULL){
        check_1(root->left, depth + 1);
    }
    if(root->right != NULL){
        check_1(root->right, depth + 1);
    }
}
bool check_2(node* root) {
    if (root == NULL) return true;
    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL)) {
        return false;
    }
    return check_2(root->left) && check_2(root->right);
}
int main(){
    int t; cin >> t;
    while(t--){
        se.clear();
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
        check_1(root, 0);
        if(se.size() == 1 && check_2(root)) cout <<"Yes" << endl;
        else cout << "No" << endl;
    }
}
