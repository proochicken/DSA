//From <https://code.ptit.edu.vn/student/question/DSA10015> 



#include <bits/stdc++.h>
using namespace std;
int n, m;
int sz[105], parent[105];
struct edge{
    int x, y, w;
};
vector<edge> E;
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
void kruskal(){
    vector<edge> v;
    int d_min = 0;
    sort(E.begin(), E.end(), [](edge& a, edge& b){
        return a.w < b.w;
    });
    for(edge e : E){
        if(v.size() == n - 1) break;
        if(Union(e.x, e.y)){
            v.push_back(e);
            d_min += e.w;
        }
    }
    cout << d_min << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        E.clear();
        
        cin >> n >> m;
        init();
        for(int i = 1; i <= m; i++){
            int x, y, w; cin >> x >> y >> w;
            E.push_back({x, y, w});
        }
        kruskal();
    }
}
