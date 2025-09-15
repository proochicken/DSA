//From <https://code.ptit.edu.vn/student/question/DSA09015> 



#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int n, m;
int color[1005];
void nhap(){
    memset(color, 0, sizeof(color));
    for(int i = 0; i < 1005; i++) adj[i].clear();
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
}
bool dfs(int u){
    color[u] = 1;
    for(int v : adj[u]){
        if(color[v] == 1){
            return true;
        }
        if(color[v] == 0){
            if(dfs(v)) return true;
        }
    }
    color[u] = 2;
    return false;
}
int main(){
    int t; cin >> t;
    while(t--){
        nhap();
        bool check = false;
        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                if(dfs(i)){
                    check = true;
                    break;
                }
            }
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
