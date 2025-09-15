//From <https://code.ptit.edu.vn/student/question/DSA07012> 


#include <bits/stdc++.h>
using namespace std;
string post_to_in(string& s){
    stack<string> st;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(isalpha(s[i])){
            st.push(string(1, c));
        }
        else{
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string tmp = "(" + op1 + c + op2 + ")";
            st.push(tmp);
        }
    }
    return st.top();
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << post_to_in(s) << endl;
    }
}