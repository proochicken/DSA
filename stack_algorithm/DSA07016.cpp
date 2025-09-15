//From <https://code.ptit.edu.vn/student/question/DSA07016> 



#include <bits/stdc++.h>
using namespace std;
void solve(string s) {
    stack<int> st;
    int num = 1;
    for (int i = 0; i <= s.size(); i++) {
        st.push(num++);
        if (i == s.size() || s[i] == 'I') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
        }
    }
    cout << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}