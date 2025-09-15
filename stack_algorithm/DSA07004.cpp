//From <https://code.ptit.edu.vn/student/question/DSA07004> 



#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> st;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    res++;
                    st.push('(');
                }
                else st.pop();
            }
        }
        cout << res + st.size() / 2 << endl;
    }
}
