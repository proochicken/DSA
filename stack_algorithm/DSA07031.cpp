//From <https://code.ptit.edu.vn/student/question/DSA07031> 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool is_operator(string c){
    return c == "+" || c == "-" || c == "*" || c == "/";
}
ll calcu_pre(vector<string>& v, int n){
    stack<ll> st;
    for(int i = n - 1; i >= 0; i--){
        string c = v[i];
        if(!is_operator(c)){
            st.push(stoll(c));
        }
        else{
            ll op1 = st.top(); st.pop();
            ll op2 = st.top(); st.pop();
            ll res = 0;
            if(c == "+") res = op1 + op2;
            if(c == "-") res = op1 - op2;
            if(c == "*") res = op1 * op2;
            if(c == "/") res = op1 / op2;
            st.push(res);
        }
    }
    return st.top();
}
int main(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        int n; cin >> n;
        cin.ignore();
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        cout << calcu_pre(v, n) << endl;
    }
}
