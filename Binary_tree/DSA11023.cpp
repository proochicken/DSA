//From <https://code.ptit.edu.vn/student/question/DSA11023> 



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
node* build_tree(vector<int>& v, int& idx, int min, int max){
    if(idx >= v.size()){
        return NULL;
    }
    int vals = v[idx];  
    if(vals < min || vals > max){
        return NULL;
    }
    node* root = new node(vals);
    idx++;
    root->left = build_tree(v, idx, min, vals - 1);
    root->right = build_tree(v, idx, vals + 1, max);
    
    return root;
}
int max_depth = 0;
void dfs(node* root, int cur_depth){
    if(root == NULL){
        max_depth = max(cur_depth - 1, max_depth);
        return;
    }
    dfs(root->left, cur_depth + 1);
    dfs(root->right, cur_depth + 1);
}
int main(){
    int t; cin >> t;
    while(t--){
        max_depth = 0;
        int n; cin >> n;
        vector<int> v;
        for(int i = 0; i <n ; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        int tmp = 0;
        node* root = build_tree(v, tmp, INT_MIN, INT_MAX);
        dfs(root, 0);
        cout << max_depth << endl;
    }
}
