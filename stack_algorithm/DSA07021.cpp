//From <https://code.ptit.edu.vn/student/question/DSA07021> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(string s){
    stack<ll> st;
    st.push(-1);
    ll ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(!st.empty()){
                ans = max(ans, i - st.top());
            }
            else{
                st.push(i);
            }
        }
    }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}
