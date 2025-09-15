//From <https://code.ptit.edu.vn/student/question/DSA04003> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 123456789;
ll binpow(ll n, ll k){
    if(k == 0) return 1;
    if(k == 1) return n;
    ll x = binpow(n, k / 2);
    if(k % 2 == 0) return (x * x) % mod;
    else return ((x * x) % mod * n) % mod;
}
int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << binpow(2, n - 1) << endl;
    }
}
