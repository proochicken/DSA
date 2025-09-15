//From <https://code.ptit.edu.vn/student/question/DSA04008> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
struct matrix{
    ll x[2][2];
    friend matrix operator * (matrix a, matrix b){
        matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res.x[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    res.x[i][j] += a.x[i][k] * b.x[k][j];
                    res.x[i][j] %= mod;
                }
            }
        }
        return res;
    }
};
matrix binpow(matrix a, int k){
    if(k == 1) return a;
    matrix tmp = binpow(a, k / 2);
    if(k % 2 == 0) return tmp * tmp;
    else return tmp * tmp * a;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        matrix a;
        for(int i = 0; i <2; i++){
            for(int j = 0; j < 2; j++){
                a.x[i][j] = 1;
            }
        }
        a.x[1][1] = 0;
        matrix res = binpow(a, n);
        cout << res.x[1][0] << endl;
    }
}
