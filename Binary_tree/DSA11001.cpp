//From <https://code.ptit.edu.vn/student/question/DSA11001> 



#include <bits/stdc++.h>
using namespace std;
struct node{
    char val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};
bool is_operator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}
node* build_tree(string s){
    stack<node*> st;
    for(int i = 0; i < s.size(); i++){
        if(!is_operator(s[i])){
            st.push(new node(s[i]));
        }
        else{
            node* a = st.top(); st.pop();
            node* b = st.top(); st.pop();
            node* tmp = new node(s[i]);
            tmp->left = b; tmp->right = a;
            st.push(tmp);
        }
    }
    return st.top();
}
void in_order(node* root){
    if(root == NULL) return;
    in_order(root->left);
    cout << root->val;
    in_order(root->right);
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        node* root = build_tree(s);
        in_order(root);
        cout << endl;
    }
}
