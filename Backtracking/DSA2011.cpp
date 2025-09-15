//From <https://code.ptit.edu.vn/student/question/DSA02011> 

#include <bits/stdc++.h>
using namespace std;
int n, s, ans = INT_MAX;
int a[35];
bool ok = false, used[35];
void ql(int start, int cnt, int sum){
    for(int j = start; j <= n; j++){
        if(sum + a[j] <= s){
            if(sum + a[j] == s){
                ok = true;
                ans = min(ans, cnt);
            }
            else if(cnt < ans){
                ql(j + 1, cnt + 1, sum + a[j]);
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ans = INT_MAX;
        ok = false;
        ql(1, 1, 0);
        if(ok) cout << ans << endl;
        else cout << -1 << endl;
    }
}
