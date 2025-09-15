//From <https://code.ptit.edu.vn/student/question/DSA02006> 



#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
vector<vector<int>> v;
void ql(int start, int sum, vector<int>& cur){
    if(sum == k){
        v.push_back(cur);
        return;
    }
    for(int i = start; i < n; i++){
        if(sum + a[i] <= k){
            cur.push_back(a[i]);
            ql(i + 1, sum + a[i], cur);
            cur.pop_back();
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        a.clear(); v.clear();
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        vector<int> tmp;
        ql(0, 0, tmp);
        if(v.empty()) cout << -1 << endl;
        else{
            for(auto x : v){
                cout << "[";
                for(int i = 0; i < x.size(); i++){
                    cout << x[i];
                    if(i != x.size() - 1) cout << " ";
                    else cout << "]";
                }
                cout << " ";
            }
            cout << endl;
        }
    }
}
