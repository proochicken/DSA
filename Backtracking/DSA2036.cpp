//From <https://code.ptit.edu.vn/student/question/DSA02036> 

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<vector<int>> res;
void ql(int start, int sum, vector<int>& cur){
    if(!cur.empty() && sum % 2 == 1){
        res.push_back(cur);
    }
    for(int i = start; i < n; i++){
        cur.push_back(v[i]);
        ql(i + 1, sum + v[i], cur);
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
        v.clear();
        res.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), greater<int>());
        vector<int> tmp;
        ql(0, 0, tmp);
        in();
    }
}