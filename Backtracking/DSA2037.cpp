//From <https://code.ptit.edu.vn/student/question/DSA02037> 



#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<vector<int>> res;
bool is_nt(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}
void ql(int start, int sum, vector<int> cur){
    if(!cur.empty() && is_nt(sum)){
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
        for(int y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        v.clear(); res.clear();
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
