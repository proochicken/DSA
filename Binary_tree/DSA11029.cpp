//From <https://code.ptit.edu.vn/student/question/DSA11029> 



#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int par[1005];
bool visited[1005];
int deg[1005];
void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            par[v] = u;
            dfs(v);
        }
    }
}
void sweep(){
    memset(par, -1, sizeof(par));
    for(int i = 1; i < 1005; i++) adj[i].clear();
    memset(visited, false, sizeof(visited));
    memset(deg, 0, sizeof(deg));
}

int main(){
    int t; cin >> t;
    while(t--){
        sweep();
        int n; cin >> n;
        for(int i = 1; i <= n - 1; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        dfs(1);
        vector<vector<int>> path;
        for(int i = 2; i <= n; i++){
            if(deg[i] == 1){
                vector<int> kq;
                int tmp = i;
                while(tmp != -1){
                    kq.push_back(tmp);
                    tmp = par[tmp];
                }
                reverse(kq.begin(), kq.end());
                path.push_back(kq);
            }
        }
        sort(path.begin(), path.end(), [](vector<int>& a, vector<int>& b){
            return a.back() < b.back();
        });
        for(auto x : path){
            for(int i : x){
                cout << i << " ";
            }
            cout << endl;
        }
    }
}
