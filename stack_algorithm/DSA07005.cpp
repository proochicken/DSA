//From <https://code.ptit.edu.vn/student/question/DSA07005> 



#include <bits/stdc++.h>
using namespace std;
string removeBrackets(string expr) {
    stack<bool> st; // true = đảo dấu, false = giữ nguyên
    st.push(false); // ngữ cảnh ngoài cùng: không đảo dấu
    string res = "";
    for (int i = 0; i < expr.length(); ++i) {
        char c = expr[i];
        if (c == '(') {
            // Dấu trước '(' quyết định việc có đảo dấu không
            if (i > 0 && expr[i - 1] == '-') {
                st.push(!st.top()); // đảo ngữ cảnh
            } else {
                st.push(st.top()); // giữ nguyên ngữ cảnh
            }
        } else if (c == ')') {
            st.pop(); // ra khỏi ngữ cảnh ngoặc
        } else if (c == '+' || c == '-') {
            if (st.top()) {
                // Đảo dấu
                res += (c == '+' ? '-' : '+');
            } else {
                res += c;
            }
        } else {
            // Là chữ cái, ghi lại
            res += c;
        }
    }
    return res;
}
int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ dòng trống sau số T
    while (T--) {
        string expr;
        getline(cin, expr);
        cout << removeBrackets(expr) << endl;
    }
    return 0;
}