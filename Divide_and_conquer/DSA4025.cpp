//From <https://code.ptit.edu.vn/student/question/DSA04025> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
struct matrix{
    ll a[2][2];
    friend matrix operator * (matrix x, matrix y){
        matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < 2; k++){
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
        int n; cin >> n;
        matrix x;
        for(int i = 0; i <2; i++){
            for(int j = 0; j < 2; j++){
                x.a[i][j] = 1;
            }
        }
        x.a[1][1] = 0;
        matrix res = binpow(x, n);
        cout << res.a[1][0] << endl;
    }
}
