//From <https://code.ptit.edu.vn/student/question/DSA02019> 



#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[25];
bool used[25][25];
int max_length = 0;
void dfs(int u, int length){
    max_length = max(max_length, length);
    for(int v : adj[u]){
        if(!used[u][v]){
            used[u][v] = used[v][u] = true;
            dfs(v, length + 1);
            used[u][v] = used[v][u] = false;
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) adj[i].clear();
        memset(used, false, sizeof(used));
        max_length = 0;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 0; i < n; i++){
            dfs(i, 0);
        }
        cout << max_length << endl;
    }
}
