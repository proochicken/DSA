//From <https://code.ptit.edu.vn/student/question/DSA09026> 



#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10005];
bool visited[10005];
int n, m, s, t;
int parent[10005];
void nhap(){
    for(int i = 1; i <= 10005; i++) adj[i].clear();
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
}
void bfs(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    parent[u] = -1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int v : adj[x]){
            if(!visited[v]){
                parent[v] = x;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
int main(){
    int q; cin >> q;
    while(q--){
        nhap();
        bfs(s);
        if(visited[t] == false){
            cout << -1 << endl;
        }
        else{
            vector<int> kq;
            while(t != -1){
                kq.push_back(t);
                t = parent[t];
            }
            reverse(kq.begin(), kq.end());
            for(int x : kq) cout << x << " ";
            cout << endl;
        }
    }
}
