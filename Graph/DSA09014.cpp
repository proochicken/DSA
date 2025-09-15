//From <https://code.ptit.edu.vn/student/question/DSA09014> 



#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> sz(1005), par(1005);
void sweep(){
    fill(sz.begin(), sz.end(), 1);
    iota(par.begin(), par.end(), 0);  // par[i] = i
}
void init(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        par[i] = i;
    }
}
int Find(int u){
    if(u == par[u]) return u;
    else return par[u] = Find(par[u]);
}
bool Union(int u, int v){
    u = Find(u), v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        sweep();
        cin >> n >> m;
        bool ok = false;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            if(!Union(x, y)){
                ok = true;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
