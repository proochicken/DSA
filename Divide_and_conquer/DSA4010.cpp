//From <https://code.ptit.edu.vn/student/question/DSA04010> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a[105];
int solve(){
    int max_sum = a[1];
    int cur_sum = a[1];
    for(int i = 2; i <= n; i++){
        cur_sum = max(a[i], cur_sum + a[i]);
        max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cout << solve() << endl;
    }
}
