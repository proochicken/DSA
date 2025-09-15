//From <https://code.ptit.edu.vn/student/question/DSA10008> 




#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, m, s;
vector<ii> adj[1005];
bool visited[1005];

int main(){
    int t; cin >> t;
    while(t--){
        memset(visited, false, sizeof(visited));
        for(int i = 1; i < 1005; i++) adj[i].clear();
        
        cin >> n >> m >> s;
        for(int i = 1; i <= m; i++){
            int x, y, w; cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        priority_queue<ii, vector<ii>, greater<ii>> q;
        q.push({0, s});
        vector<int> d(n + 1, 1e9); d[s] = 0;
        while(!q.empty()){
            ii t = q.top(); q.pop();
            int dis = t.first, u = t.second;
            if(visited[u]) continue;
            visited[u] = true;
            for(ii v : adj[u]){
                int x = v.first, w = v.second;
                if(d[x] > d[u] + w){
                    d[x] = d[u] + w;
                    q.push({d[x], x});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }
}
