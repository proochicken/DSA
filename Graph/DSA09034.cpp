//From <https://code.ptit.edu.vn/student/question/DSA09034> 



#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
int a[105][105];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char x; cin >> x;
            if(x == 'W') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
}
void dfs(int i, int j){
    a[i][j] = 0;
    for(int k = 0; k < 8; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1){
            dfs(i1, j1);
        }
    }
}
int main(){
    nhap();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
}
