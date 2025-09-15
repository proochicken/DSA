//From <https://code.ptit.edu.vn/student/question/DSA02028> 


#include <bits/stdc++.h>
using namespace std;
int a[15];
int target, ans = 0;
int n, k;
void ql(int pos, int cnt){
    if(cnt > k + 1) return;
    if(pos == n + 1){
        if(cnt == k) ans++;
        return;
    }
    int current_sum = 0;
    for(int i = pos; i <= n; i++){
        current_sum += a[i];
        if(current_sum == target){
            ql(i + 1, cnt + 1);
        }
    }
}
int main(){
    cin >> n >> k;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % k != 0) cout << 0 << endl;
    else{
        target = sum / k;
        ql(1, 0);
        cout << ans << endl;
    }
}
