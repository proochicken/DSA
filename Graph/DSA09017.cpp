//From <https://code.ptit.edu.vn/student/question/DSA09017> 



#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visited[1005];
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
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 1005; i++) adj[i].clear();
        int n; cin >> n;
        for(int i = 1; i <= n - 1; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }
        if(cnt == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
