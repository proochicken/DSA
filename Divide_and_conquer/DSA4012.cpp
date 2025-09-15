//From <https://code.ptit.edu.vn/student/question/DSA04012> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> ii;

int main(){
    int t; cin >> t;
    while(t--){
        int m, n; cin >> m >> n;
        vector<ii> p, q;
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            p.push_back({x, i});
        }
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            q.push_back({x, i});
        }
        map<int, int> mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                ii x;
                x.first = p[i].first * q[j].first;
                x.second = p[i].second + q[j].second;
                
                if(mp[x.second] != 0){
                    mp[x.second] += x.first;
                }
                else{
                    mp[x.second] = x.first;
                }
            }
        }
        for(ii x : mp){
            cout << x.second << " ";
        }
        cout << endl;
    }
}