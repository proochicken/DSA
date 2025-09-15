//From <https://code.ptit.edu.vn/student/question/DSA02012> 



#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int n, m, ans = 0;
void dfs(int i, int j){
    if(i == m && j == n){
        ans++;
        return;
    }
    if(i + 1 >= 1 && i + 1 <= m && j >= 1 && j <= n){
        dfs(i + 1, j); 
    }
    if(i >= 1 && i <= m && j + 1 >= 1 && j + 1 <= n){
        dfs(i, j + 1);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        ans = 0;
        cin >> m >> n;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        dfs(1, 1);
        cout << ans << endl;
    }
}
