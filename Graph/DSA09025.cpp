//From <https://code.ptit.edu.vn/student/question/DSA09025> 



#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<int> adj[10005];
int parent[10005];
bool visited[10005];
void nhap(){
    for(int i = 1; i <= 10005; i++) adj[i].clear();
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    // for(int i = 1; i <= n; i++){
    //     sort(adj[i].begin(), adj[i].end());
    // }
}
void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while(q--){
        nhap();
        dfs(s);
        if(!visited[t]){
            cout << -1 << endl;
        }
        else{
            vector<int> kq;
            while(t != -1){
                kq.push_back(t);
                t = parent[t];
            }
            reverse(kq.begin(), kq.end());
            for(int x : kq){
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
