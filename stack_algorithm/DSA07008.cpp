//From <https://code.ptit.edu.vn/student/question/DSA07008> 



#include <bits/stdc++.h>
using namespace std;
int prio(char c){
    if(c == '^') return 4;
    if(c == '*' || c == '/') return 3;
    if(c == '+' || c == '-') return 2;
    return 1;
}
string solve(string& s){
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') st.push(s[i]);
        else if(s[i]  == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
            while(!st.empty() && prio(st.top()) >= prio(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else res += s[i];
    }
    while(!st.empty()){
        if(st.top() != '(') res += st.top();
        st.pop();
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}
