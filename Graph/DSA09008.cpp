//From <https://code.ptit.edu.vn/student/question/DSA09008> 



#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visited[1005];
int cnt = 0;
void sweep(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 1005; i++) adj[i].clear();
    cnt = 0;
}
void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        sweep();
        int n, m; cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        cout << cnt << endl;
    }
}
