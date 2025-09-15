//From <https://code.ptit.edu.vn/student/question/DSA02027> 

#include <bits/stdc++.h>
using namespace std;
int n, ans = INT_MAX, sum;
int a[20][20], x[25];
bool visited[25];
void ql(int i){
    for(int j = 1; j <= n; j++){
        if(!visited[j]){
            x[i] = j;
            visited[j] = true;
            sum += a[x[i]][x[i - 1]];
            if(i == n){
                ans = min(ans, sum + a[x[n]][x[1]]);
            }
            else if(sum <= ans && i < n){
                ql(i + 1);
            }
            visited[j] = false;
            sum -= a[x[i]][x[i-1]];
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    visited[1] = 1;
    x[1] = 1;
    ql(2);
    cout << ans;
}
