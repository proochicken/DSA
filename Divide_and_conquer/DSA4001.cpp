//From <https://code.ptit.edu.vn/student/question/DSA04001> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll binpow(ll n, ll k){
    if(k == 0) return 1;
    if(k == 1) return n;
    ll tmp = binpow(n, k / 2);
    if(k % 2 == 0)
        return (tmp * tmp) % mod;
    else
        return ((tmp * tmp) % mod * n) % mod;
}
int main(){
    int t; cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        cout << binpow(n, k) << endl;
    }
}
