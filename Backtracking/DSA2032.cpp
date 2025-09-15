//From <https://code.ptit.edu.vn/student/question/DSA02032> 



#include <bits/stdc++.h>
using namespace std;
int n, s;
vector<int> v;
vector<vector<int>> res;

void ql(int start, int sum, vector<int>& cur){
    if(sum == s){
        res.push_back(cur);
        return;
    }
    for(int j = start; j < n; j++){
        if(sum + v[j] <= s){
            cur.push_back(v[j]);
            ql(j, sum + v[j], cur);
            cur.pop_back();
        }
    }
}
void in(){
    for(auto x : res){
        cout << "{";
        for(int i = 0; i < x.size(); i++){
            cout << x[i];
            if(i != x.size() - 1) cout << " ";
        }
        cout << "} ";
    }
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        v.clear();
        res.clear();
        cin >> n >> s;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        vector<int> tmp;
        ql(0, 0, tmp);
        if(res.size() != 0){
            cout << res.size() << " ";
            in();
        }
        else cout << -1 << endl;
    }
}
