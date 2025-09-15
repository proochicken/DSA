//From <https://code.ptit.edu.vn/student/question/DSA08021> 

#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005][1005];
bool visited[1005][1005];
int bfs(int i, int j){
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, 0});
    visited[i][j] = true;
    while(!q.empty()){
        auto top = q.front(); q.pop();
        int ci = top.first.first;
        int cj = top.first.second;
        int step = top.second;
        if(ci == m && cj == n){
            return step;
        }
        int val = a[ci][cj];
        // Sang phải
        int nj = cj + val;
        if(nj >= 1 && nj <= n && !visited[ci][nj]){
            visited[ci][nj] = true;
            q.push({{ci, nj}, step + 1});
        }
        // Xuống dưới
        int ni = ci + val;
        if(ni >= 1 && ni <= m && !visited[ni][cj]){
            visited[ni][cj] = true;
            q.push({{ni, cj}, step + 1});
        }
    }
    return -1; // Không đến được
}
int main(){
    int t; cin >> t;
    while(t--){
        memset(visited, false, sizeof(visited));
        memset(a, 0, sizeof(a));
        cin >> m >> n;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        int result = bfs(1, 1);
        cout << result << endl;
    }
    return 0;
}
