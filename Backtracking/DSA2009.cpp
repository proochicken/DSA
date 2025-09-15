//From <https://code.ptit.edu.vn/student/question/DSA02009> 

#include <bits/stdc++.h>
using namespace std;
int n, k, target = 0;
bool ok = false, visited[25];
int a[25];
void ql(int start, int s, int cnt){
    if(cnt == k){
        ok = true;
        return;
    }
    if(ok == true) return;
    for(int j = start; j <= n; j++){
        if(s + a[j] <= target && !visited[j]){
            visited[j] = true;
            if(s + a[j] == target){
                ql(1, 0, cnt + 1);
            }
            else if(s + a[j] < target){
                ql(j + 1, s + a[j], cnt);
            }
            visited[j] = false;
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        int sum = 0;
        ok = false;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % k != 0){
            cout << 0 << endl;
            continue;
        }
        else{
            target = sum / k;
            ql(1, 0, 0);
            if(ok) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}
