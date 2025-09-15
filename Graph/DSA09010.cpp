//From <https://code.ptit.edu.vn/student/question/DSA09010> 



#include <bits/stdc++.h>
using namespace std;
int n, m, timer = 0;
vector<int> adj[1005];
bool visited[1005], in_stack[1005];
int disc[1005], low[1005];
stack<int> st;
int scc = 0;
void sweep(){
    timer = 0;
    for(int i = 0; i < 1005; i++) adj[i].clear();
    memset(visited, false, sizeof(visited));
    memset(in_stack, false, sizeof(in_stack));
    memset(disc, 0, sizeof(disc));
    memset(low, false, sizeof(low));
    scc = 0;
}
void tarjan(int u, int par){
    visited[u] = true;
    disc[u] = low[u] = timer++;
    st.push(u);
    in_stack[u] = true;
    
    for(int v : adj[u]){
        if(v == par) continue;
        if(!visited[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stack[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(low[u] == disc[u]){
        scc++;
        while(st.top() != u){
            in_stack[st.top()] = false;
            st.pop();
        }
        in_stack[st.top()] = false;
        st.pop();
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        sweep();
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                tarjan(i, -1);
            }
        }
        if(scc == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
