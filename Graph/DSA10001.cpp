//From <https://code.ptit.edu.vn/student/question/DSA10001> 



#include <bits/stdc++.h>
using namespace std;
int a[505][505];
bool visited[505][505];
int si, sj, ti, tj;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool found = false;
int n, m;
void dfs(int i, int j, int dir, int k){
    if(k > 2) return;
    if(i == ti && j == tj){
        found = true;
        return;
    }
    visited[i][j] = true;
    for(int p = 0; p < 4; p++){
        int i1 = i + dx[p], j1 = j + dy[p];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1] != '*'){
            int new_turn = k;
            if(dir != -1 && dir != p) new_turn++;
            dfs(i1, j1, p, new_turn);
        }
    }
    visited[i][j] = false;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char c; cin >> c;
                if(c == 'S'){
                    si = i; sj = j;
                }
                if(c == 'T'){
                    ti = i; tj = j;
                }
                a[i][j] = c;
            }
        }
        memset(visited, false, sizeof(visited));
        found = false;
        dfs(si, sj, -1, 0);
        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
