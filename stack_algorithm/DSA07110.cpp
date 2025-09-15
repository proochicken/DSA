//From <https://code.ptit.edu.vn/student/question/DSA07110> 




#include <bits/stdc++.h>
using namespace std;
bool check_valid(string& s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            char c = st.top();
            if((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '[')){
                st.pop();
            }
            else return false;
        }
    }
    return st.empty();
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        if(check_valid(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}