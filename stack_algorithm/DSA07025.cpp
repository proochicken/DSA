//From <https://code.ptit.edu.vn/student/question/DSA07025> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Hàm tính giá trị biểu thức hậu tố
ll evaluate_postfix(const vector<string>& tokens) {
    stack<ll> st;
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            ll b = st.top(); st.pop();
            ll a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            if (token == "-") st.push(a - b);
            if (token == "*") st.push(a * b);
            if (token == "/") st.push(a / b); // chia nguyên
        } else {
            st.push(stoll(token)); // chuyển chuỗi sang số nguyên
        }
    }
    return st.top();
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cin.ignore(); // bỏ dòng trắng
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
        cout << evaluate_postfix(tokens) << endl;
    }
    return 0;
}