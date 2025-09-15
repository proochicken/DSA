//From <https://code.ptit.edu.vn/student/question/DSA10006> 



#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visited[1005];
int cnt = 1;
vector<pair<int, int>> res;
void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            cnt++;
            res.push_back({u, v});
            dfs(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 0; i < 1005; i++) adj[i].clear();
        memset(visited, false, sizeof(visited));
        res.clear();
        cnt = 1;
        int n, m, u;
        cin >> n >> m >> u;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(u);
        if(cnt == n){
            for(auto i : res){
                cout << i.first << " " << i.second << endl;
            }
        }
        else cout << -1 << endl;
    }
}
