//From <https://code.ptit.edu.vn/student/question/DSA07010> 



#include <bits/stdc++.h>
using namespace std;
bool is_operator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}
string pre_to_post(string& s){
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i--){
        char c = s[i];
        
        if(is_operator(c)){
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string tmp = op1 + op2 + c;
            st.push(tmp);
        }
        else{
            st.push(string(1, c));
        }
    }
    return st.top();
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << pre_to_post(s) << endl;
    }
}
