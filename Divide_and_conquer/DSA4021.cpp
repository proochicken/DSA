//From <https://code.ptit.edu.vn/student/question/DSA04021> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[94];
void make_fibo(){
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= 93; i++){
        f[i] = f[i - 2] + f[i - 1];
    }
}
ll find(ll n, ll k){
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(k <= f[n - 2]) return find(n - 2, k);
    else return find(n - 1, k - f[n - 2]);
}
int main(){
    make_fibo();
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        cout << find(n, k) << endl;
    }
}
