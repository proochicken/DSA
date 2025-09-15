//From <https://code.ptit.edu.vn/student/question/DSA04009> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
struct matrix{
    ll a[15][15];
    int n;
    friend matrix operator * (matrix x, matrix y){
        matrix res;
        res.n = x.n;
        for(int i = 0; i < x.n; i++){
            for(int j = 0; j < x.n; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < x.n; k++){
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
        int n, k; cin >> n >> k;
        matrix x;
        x.n = n;
        for(int i = 0; i <n; i++){
            for(int j = 0; j< n; j++){
                cin >> x.a[i][j];
            }
        }
        matrix res = binpow(x, k);
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                cout << res.a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
