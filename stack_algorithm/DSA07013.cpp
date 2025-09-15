//From <https://code.ptit.edu.vn/student/question/DSA07013> 



#include <bits/stdc++.h>
using namespace std;
int evaluatePostfix(string exp) {
    stack<int> st;
    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0'); // chuyển từ ký tự sang số
        } else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            int res;
            switch (c) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break; // phép chia lấy phần nguyên
            }
            st.push(res);
        }
    }
    return st.top(); // kết quả cuối cùng
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string exp;
        cin >> exp;
        cout << evaluatePostfix(exp) << endl;
    }
    return 0;
}
