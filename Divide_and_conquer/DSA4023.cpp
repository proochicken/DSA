//From <https://code.ptit.edu.vn/student/question/DSA04023> 



#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            int target = a[i] + k;
            auto it = lower_bound(a.begin() + i + 1, a.end(), target);
            count += (it - (a.begin() + i + 1));
        }
        cout << count << '\n';
    }
    return 0;
}
