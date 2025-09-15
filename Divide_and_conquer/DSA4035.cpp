//From <https://code.ptit.edu.vn/student/question/DSA04035> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll binpow(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a;
    ll x = binpow(a, b / 2);
    if(b % 2 == 0) return x * x % mod;
    else return ((x * x) % mod * a) % mod;
}
int main(){
    ll a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        cout << binpow(a, b) << endl;
    }
}
