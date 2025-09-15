//From <https://code.ptit.edu.vn/student/question/DSA09032> 



#include <bits/stdc++.h>
using namespace std;
int sz[100005], parent[100005];
int n, m;
void init(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}
int Find(int u){
    if(u == parent[u]) return u;
    else return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}


int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        init();
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            Union(x, y);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(parent[i] == i){
                cnt = max(cnt, sz[i]);
            }
        }
        cout << cnt << endl;
    }
}
