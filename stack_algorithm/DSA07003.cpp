//From <https://code.ptit.edu.vn/student/question/DSA07003> 



#include <bits/stdc++.h>
using namespace std;
bool isRedundant(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == ')') {
            char top = st.top();
            st.pop();
            bool hasOperator = false;
            while (top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    hasOperator = true;
                if (st.empty()) break; // đề phòng sai biểu thức
                top = st.top();
                st.pop();
            }
            if (!hasOperator) return true; // dấu ngoặc dư thừa
        } else {
            st.push(ch);
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    cin.ignore(); // để đọc dòng tiếp theo đúng cách
    while (t--) {
        string s;
        getline(cin, s);
        if (isRedundant(s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
