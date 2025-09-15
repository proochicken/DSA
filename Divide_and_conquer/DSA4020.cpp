//From <https://code.ptit.edu.vn/student/question/DSA04020> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int find(int a[], int l, int r, int k){
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == k){
            return m;
        }
        else if(a[m] < k){
            l = m + 1;
        }
        else r = m - 1;
    }
    return -1;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int k; cin >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int pos = find(a, 0, n - 1, k);
        if(pos == -1) cout << "NO" << endl;
        else cout << pos + 1 << endl;
    }
}
