//From <https://code.ptit.edu.vn/student/question/DSA02004> 



#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
bool used[10][10];
vector<string> res;
string path = "DLRU";
int dx[] = {1, 0, 0, -1}; // D, L, R, U
int dy[] = {0, -1, 1, 0};
void ql(int i, int j, string s) {
    if (i == n - 1 && j == n - 1) {
        res.push_back(s);
        return;
    }
    for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && a[ni][nj] == 1 && !used[ni][nj]) {
            used[ni][nj] = true;
            ql(ni, nj, s + path[k]);
            used[ni][nj] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        res.clear();
        memset(used, false, sizeof(used));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        if (a[0][0] == 1 && a[n-1][n-1] == 1) {
            used[0][0] = true;
            ql(0, 0, "");
        }
        if (res.empty()) {
            cout << -1;
        } else {
            sort(res.begin(), res.end());
            for (string s : res) cout << s << " ";
        }
        cout << "\n";
    }
}
