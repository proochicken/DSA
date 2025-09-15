//From <https://code.ptit.edu.vn/student/question/DSA04004> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Find(ll n, ll k){
    if(n == 1) return 1;
    if(k % 2 == 1) return 1;
    if(k == (ll)pow(2, n - 1)) return n;
    if(k < (ll) pow(2, n - 1)) return Find(n - 1, k);
    if(k > (ll)pow(2, n - 1)) return Find(n - 1, k - (ll)pow(2, n - 1));
}
int main(){
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        cout << Find(n, k) << endl;
    }
}
