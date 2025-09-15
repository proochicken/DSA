//From <https://code.ptit.edu.vn/student/question/DSA02038> 



#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
vector<vector<int>> res;
void ql(int start, vector<int>& cur){
    if(cur.size() == k){
        res.push_back(cur);
        return;
    }
    for(int i = start; i < n; i++){
            cur.push_back(v[i]);
            ql(i + 1, cur);
            cur.pop_back();
    }
}
void in(){
    sort(res.begin(), res.end());
    for(auto x : res){
        for(int i : x){
            cout << i << " ";
        }
        cout << endl;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        res.clear(); v.clear();
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        vector<int> tmp;
        ql(0, tmp);
        in();
    }
}
