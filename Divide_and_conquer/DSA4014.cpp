//From <https://code.ptit.edu.vn/student/question/DSA04014> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll merge(ll a[], int l, int m, int r){
    vector<ll> v1(a + l, a + m + 1);
    vector<ll> v2(a + m + 1, a + r + 1);
    ll i = 0, j = 0, idx = l;
    ll cnt = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] <= v2[j]){
            a[idx++] = v1[i++];
        }
        else{
            cnt += v1.size() - i;
            a[idx++] = v2[j++];
        }
    }
    while(i < v1.size()){
        a[idx++] = v1[i++];
    }
    while(j < v2.size()){
        a[idx++] = v2[j++];
    }
    return cnt;
}
ll merge_sort(ll a[], int l, int r){
    if(l == r) return 0;
    ll m = (l + r) / 2;
    return merge_sort(a, l, m) + merge_sort(a, m + 1, r) + merge(a, l, m, r);
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n + 1];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << merge_sort(a, 0, n - 1) << endl;;
    }
}
