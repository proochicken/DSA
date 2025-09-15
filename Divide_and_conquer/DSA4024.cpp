//From <https://code.ptit.edu.vn/student/question/DSA04024> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
struct matrix{
    ll a[15][15];
    ll n;
    friend matrix operator * (matrix x, matrix y){
        matrix res;
        res.n = x.n;
        for(int i = 1; i <= x.n; i++){
            for(int j = 1; j <= y.n; j++){
                res.a[i][j] = 0;
                for(int k = 1; k <= x.n; k++){
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};
matrix binpow(matrix x, int k){
    if(k == 1) return x;
    matrix tmp = binpow(x, k / 2);
    if(k % 2 == 0) return tmp * tmp;
    else return tmp * tmp * x;
}
int main(){
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        matrix x;
        x.n = n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int tmp; cin >> tmp;
                x.a[i][j] = tmp;
            }
        }
        matrix kq = binpow(x, k);
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            sum += kq.a[i][n];
            sum %= mod;
        }
        cout << sum << endl;
    }
}
