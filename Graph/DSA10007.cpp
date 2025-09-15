//From <https://code.ptit.edu.vn/student/question/DSA10007> 



#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> res;
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int top = q.front(); q.pop();
        for(int v : adj[top]){
            if(!visited[v]){
                visited[v] = true;
                res.push_back({top, v});
                q.push(v);
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        res.clear();
        for(int i = 1; i < 1005; i++) adj[i].clear();
        memset(visited, false, sizeof(visited));
        int n, m, s;
        cin >> n >> m >> s;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        bfs(s);
        if(res.size() == n - 1){
            for(auto x : res){
                cout << x.first << " " << x.second << endl;
            }
        }
        else cout << -1 << endl;
    }
}
