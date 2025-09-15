//From <https://code.ptit.edu.vn/student/question/DSA09012> 



#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int n, m, timer = 0;
int disc[1005], low[1005];
bool is_dinh_tru[1005], visited[1005];
void sweep(){
    for(int i = 0; i < 1005; i++) adj[i].clear();
    timer = 0;
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(is_dinh_tru, false, sizeof(is_dinh_tru));
    memset(visited, false, sizeof(visited));
}
void tarjan(int u, int par){
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int child = 0;
    for(int v : adj[u]){
        if(v == par) continue;
        if(!visited[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            child++;
            if(par != -1 && disc[u] <= low[v]){
                is_dinh_tru[u] = true;
            }
        }
        else{
            low[u] = min(low[u], disc[v]);
        }
    }
    if(par == -1 && child > 1) is_dinh_tru[u] = true;
}
int main(){
    int t; cin >> t;
    while(t--){
        sweep();
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                tarjan(i, -1);
            }
        }
        for(int i = 1; i <= n; i++){
            if(is_dinh_tru[i]) cout << i << ' ';
        }
        cout << endl;
    }
}