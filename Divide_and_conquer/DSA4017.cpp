//From <https://code.ptit.edu.vn/student/question/DSA04017> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int find(ll a[], ll b[], int n){
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        if(i == n) return n;
        if(a[i] == b[i]) cnt++;
        else{
            return cnt;
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ll b[n];
        for(int i = 1; i <= n - 1; i++){
            cin >> b[i];
        }
        cout << find(a, b, n) << endl;
    }
}
