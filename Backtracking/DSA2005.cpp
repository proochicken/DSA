//From <https://code.ptit.edu.vn/student/question/DSA02005> 



#include <bits/stdc++.h>
using namespace std;
string s;
bool visited[15];      // đánh dấu ký tự đã dùng
string current;        // hoán vị đang xây dựng
vector<string> res;
void backtrack(int n) {
    if (current.length() == n) {
        res.push_back(current);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            current.push_back(s[i]);
            backtrack(n);
            current.pop_back();
            visited[i] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> s;
        int n = s.length();
        res.clear();
        current = "";
        fill(visited, visited + n, false);
        backtrack(n);
        sort(res.begin(), res.end()); // đảm bảo thứ tự từ điển
        for (string x : res) cout << x << " ";
        cout << endl;
    }
}
