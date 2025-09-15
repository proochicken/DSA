//From <https://code.ptit.edu.vn/student/question/DSA07014> 



#include <bits/stdc++.h>
using namespace std;
int calcu_pre(string s){
    stack<int> st;
    for(int i = s.size() - 1; i >= 0; i--){
        char c = s[i];
        if(isdigit(c)){
            st.push(c - '0');
        }
        else{
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            int res = 0;
            if(c == '+') res = op1 + op2;
            if(c == '-') res = op1 - op2;
            if(c == '*') res = op1 * op2;
            if(c == '/') res = op1 / op2;
            st.push(res);
        }
    }
    return st.top();
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << calcu_pre(s) << endl;
    }
}
