//From <https://code.ptit.edu.vn/student/question/DSA09030> 

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
int color[1005];
bool ok = true;
void nhap(){
    ok = true;
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= 1005; i++) adj[i].clear();
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(int u, int status){
    color[u] = status;
    for(int v : adj[u]){
        if(color[v] == 0){
            dfs(v, 3 - status);
        }
        else{
            if(color[u] == color[v]){
                ok = false;
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        nhap();
        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                dfs(i, 1); // tô màu từ các đỉnh chưa duyệt
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
