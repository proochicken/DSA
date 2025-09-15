//From <https://code.ptit.edu.vn/student/question/DSA07041> 



#include <bits/stdc++.h>
using namespace std;
int solve(string& s){
    stack<char> st;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push('(');
        }
        else{
            if(!st.empty()){
                cnt++;
                st.pop();
            }
        }
    }
    return cnt * 2;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}