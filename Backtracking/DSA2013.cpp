//From <https://code.ptit.edu.vn/student/question/DSA02013> 

#include <bits/stdc++.h>
using namespace std;
int s, p, n;
vector<int> primes;
vector<vector<int>> res;
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
void ql(int sum, int start, vector<int>& cur) {
    if (cur.size() > n || sum > s) return;
    if (cur.size() == n && sum == s) {
        res.push_back(cur);
        return;
    }
    for (int i = start; i < primes.size(); i++) {
        if(cur.size() < n && sum + primes[i] <= s){
            cur.push_back(primes[i]);
            ql(sum + primes[i], i + 1, cur); // i+1 để tránh dùng lại số
            cur.pop_back();
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> p >> s;
        // Tạo danh sách số nguyên tố > p và ≤ s
        primes.clear();
        for (int i = p + 1; i <= s; i++) {
            if (is_prime(i)) primes.push_back(i);
        }
        res.clear();
        vector<int> tmp;
        ql(0, 0, tmp);
        cout << res.size() << endl;
        for (auto v : res) {
            for (int x : v) cout << x << " ";
            cout << endl;
        }
    }
}
