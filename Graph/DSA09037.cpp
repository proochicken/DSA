//From <https://code.ptit.edu.vn/student/question/DSA09037> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int k, n, m;
vector<int> ke[100005];
bool used[100005];
int dem[10005];
void dfs(int u){
    dem[u]++;
    used[u] = true;
    for(int v : ke[u]){
        if(!used[v]){
            dfs(v);
        }
    }
}
int main(){
    cin >> k >> n >> m;
    int address[k];
    for(int &x : address) cin >> x;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        // ke[y].push_back(x);
    }
    for(int v : address){
        memset(used, false, sizeof(used));
        dfs(v);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(dem[i] == k) cnt++;
    }
    cout << cnt;
}
