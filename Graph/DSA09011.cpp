//From <https://code.ptit.edu.vn/student/question/DSA09011> 



#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[505][505];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool visited[505][505];
void dfs(int i, int j){
    visited[i][j] = true;
    for(int k = 0; k < 8; k++){
        int i1 = dx[k] + i, j1 = dy[k] + j;
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1 && !visited[i1][j1]){
            dfs(i1, j1);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        memset(visited, false, sizeof(visited));
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] && !visited[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}