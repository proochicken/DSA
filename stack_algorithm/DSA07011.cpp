//From <https://code.ptit.edu.vn/student/question/DSA07011> 



#include <bits/stdc++.h>
using namespace std;
string post_to_pre(string& s){
    stack<string> st;
    string res = "";
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        
        if(isalpha(c)){
            st.push(string(1,c));
        }
        else{
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string tmp = c + op1 + op2;
            st.push(tmp);
        }
    }
    return st.top();
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << post_to_pre(s) << endl;
    }
}