//From <https://code.ptit.edu.vn/student/question/DSA08007> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void bdn(ll n) {
    queue<ll> q;
    ll cnt = 0;
    q.push(1);
    while (!q.empty()) {
        ll s = q.front(); q.pop();
        if (s > n) break;
        cnt++;
        q.push(s* 10);
        q.push(s* 10 + 1);
    }
    cout << cnt << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        bdn(n);
    }
    return 0;
}
