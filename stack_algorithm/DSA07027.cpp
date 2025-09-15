//From <https://code.ptit.edu.vn/student/question/DSA07027> 



#include <bits/stdc++.h>
using namespace std;
void solve(vector<int>& a, int n){
    stack<int> st;
    vector<int> res(n);
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && a[i] >= st.top()){
            st.pop();
        }
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
        st.push(a[i]);
    }
    for(int x : res) cout << x << " ";
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        solve(a, n);
    }
}