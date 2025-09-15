//From <https://code.ptit.edu.vn/student/question/DSA11022> 



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
node* build_tree(vector<int>& pre, int& idx, int min, int max){
    if(idx >= pre.size()) return NULL;
    
    int x = pre[idx];
    if(x < min || x > max){
        return NULL;
    }
    idx++;
    node* root = new node(x);
    root->left = build_tree(pre, idx, min, x - 1);
    root->right = build_tree(pre, idx, x + 1, max);
    return root;
}
int cnt = 0;
void check_trung_gian(node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->left != NULL || root->right != NULL || (root->left != NULL && root->right != NULL)){
        cnt++;
    }
    check_trung_gian(root->left);
    check_trung_gian(root->right);
}
int main(){
    int t; cin >> t;
    while(t--){
        cnt = 0;
        int n; cin >> n;
        vector<int> pre;
        for(int i = 0; i <n ; i++){
            int x; cin >> x;
            pre.push_back(x);
        }
        int tmp = 0;
        node* root = build_tree(pre, tmp, INT_MIN, INT_MAX);
        check_trung_gian(root);
        cout <<cnt << endl;
    }
}
