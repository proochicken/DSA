//From <https://code.ptit.edu.vn/student/question/DSA09013> 



#include <bits/stdc++.h>
using namespace std;
int n, m, timer = 0;
vector<int> adj[1005];
bool visited[1005];
int disc[1005], low[1005];
vector<pair<int, int>> bridge;
void sweep(){
    timer = 0;
    for(int i = 0; i < 1005; i++) adj[i].clear();
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));
    memset(visited, false, sizeof(visited));
    bridge.clear();
}
void dfs(int u, int par){
    disc[u] = low[u] = ++timer;
    for(int v : adj[u]){
        if(v == par) continue;
        if(disc[v] == -1){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(disc[u] < low[v]){
                bridge.push_back({min(u, v), max(u, v)});
            }
        }
        else 
            low[u] = min(low[u], disc[v]);
    }
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
            sort(adj[i].begin(), adj[i].end());
        }
        for(int i = 1; i <= n; i++){
            if(disc[i] == -1){
                dfs(i, -1);
            }
        }
        for(auto x : bridge){
            cout << x.first  <<" " << x.second << " ";
        }
        cout << endl;
    }
}
