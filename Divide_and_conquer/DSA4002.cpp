//From <https://code.ptit.edu.vn/student/question/DSA04002> 


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll reverse_digit(ll n){
    string s = "";
    string tmp = to_string(n);
    for(int i = tmp.size() - 1; i >= 0; i--){
        s += tmp[i];
    }
    ll x = stoll(s);
    return x;
}
ll binpow(ll n, ll k){
    if(k == 0) return 1;
    if(k == 1) return n;
    ll x = binpow(n, k / 2);
    if(k % 2 == 0) return (x * x) % mod;
    else return ((x * x) % mod * n) % mod;
}
int main(){
    int t = 1; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll r = reverse_digit(n);
        cout << binpow(n, r) << endl;
    }
}
