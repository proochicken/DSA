//From <https://code.ptit.edu.vn/student/question/DSA05009> 



#include <bits/stdc++.h>
using namespace std;
int n, target;
vector<int> a;
bool ok;
void ql(int start, int s) {
    if (s == target) {
        ok = true;
        return;
    }
    for (int i = start; i < n; i++) {
        if (s + a[i] <= target) {
            ql(i + 1, s + a[i]);
        }
        if (ok) return; // dừng sớm nếu đã tìm thấy
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        a.clear();
        ok = false;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back(x);
            sum += x;
        }
        if (sum % 2 != 0) {
            cout << "NO\n";
        } else {
            target = sum / 2;
            ql(0, 0);
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
}
