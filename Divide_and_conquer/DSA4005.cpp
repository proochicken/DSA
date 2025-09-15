//From <https://code.ptit.edu.vn/student/question/DSA04005> 


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll F[94];
void build_fibo(){
    F[1] = 1;
    F[2] = 1;
    for(int i = 3; i <= 93; i++){
        F[i] = F[i - 2] + F[i - 1];
    }
}
char Find(ll n, ll k){
    if(n == 1) return 'A';
    if(n == 2) return 'B';
    if(k <= F[n - 2]) return Find(n - 2, k);
    else return Find(n - 1, k - F[n - 2]);
}
int main(){
    int t; cin >> t;
    build_fibo();
    while(t--){
        ll n, k; cin >> n >> k;
        cout << Find(n, k) << endl;
    }
}
