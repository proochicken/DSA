//From <https://code.ptit.edu.vn/student/question/DSA09028> 



#include <bits/stdc++.h>
using namespace std;
int v, e, m;
vector<int> adj[105];
int color[105];
void nhap(){
    memset(color, 0, sizeof(color));
    for(int i = 1; i<= 105; i++) adj[i].clear();
    cin >> v >> e >> m;
    for(int i = 1; i <= e; i++){
        int x, y; cin >>x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
bool is_paint(int u, int c){
    for(int x : adj[u]){
        if(color[x] == c) return false;
    }
    return true;
}
bool paint_posible(int u){
    if(u == v + 1) return true;
    for(int i = 1; i <= m; i++){
        if(is_paint(u, i)){
            color[u] = i;
            if(paint_posible(u + 1)) return true;
            color[u] = 0;
        }
    }
    return false;
}
int main(){
    int t; cin >> t;
    while(t--){
        nhap();
        if(paint_posible(1)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
