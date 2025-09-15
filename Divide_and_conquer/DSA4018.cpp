//From <https://code.ptit.edu.vn/student/question/DSA04018> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int find(int a[], int l, int r){
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == 0){
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int pos = find(a, 1, n);
        if(pos == -1) cout << 0 << endl;
        else cout << pos << endl;
    }
}
