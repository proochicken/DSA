//From <https://code.ptit.edu.vn/student/question/DSA11002> 




#include <bits/stdc++.h>
using namespace std;
struct node{
    string val;
    node* left; 
    node* right;
    node(string s){
        val = s;
        left = right = NULL;
    }
};
node* build_tree(vector<string>& v, int& idx){
    node* root = new node(v[idx]);
    queue<node* > q;
    q.push(root);
    idx++;
    while(!q.empty() && idx < v.size()){
        node* top = q.front(); q.pop();
        if(top->left == NULL && idx < v.size()){
            top->left = new node(v[idx++]);
            q.push(top->left);
        }
        if(top->right == NULL && idx < v.size()){
            top->right = new node(v[idx++]);
            q.push(top->right);
        }
    }
    return root;
}
int calcu(node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return stoi(root->val);
    int sum_left = calcu(root->left);
    int sum_right = calcu(root->right);
    if(root->val == "+") return sum_left + sum_right;
    if(root->val == "-") return sum_left - sum_right;
    if(root->val == "*") return sum_left * sum_right;
    if(root->val == "/") return sum_left / sum_right;
    return 0;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> v;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            v.push_back(s);
        }
        int tmp = 0;
        node* root = build_tree(v, tmp);
        cout << calcu(root) << endl;
    }
}
