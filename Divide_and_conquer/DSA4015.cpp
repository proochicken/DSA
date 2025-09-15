//From <https://code.ptit.edu.vn/student/question/DSA04015> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int find(ll a[], int l, int r, ll x){
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] <= x){
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll x; cin >> x;
        ll a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cout << find(a, 1, n, x) << endl;
    }
}
