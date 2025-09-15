//From <https://code.ptit.edu.vn/student/question/DSA09027> 



#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
bool visited[1005];
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
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
    int query; cin >> query;
    while(query--){
        for(int i = 1; i <= 1005; i++) adj[i].clear();
        nhap();
        int q; cin >> q;
        while(q--){
            memset(visited, false, sizeof(visited));
            int s, t; cin >> s >> t;
            dfs(s);
            if(visited[t]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
