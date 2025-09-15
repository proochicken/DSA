//From <https://code.ptit.edu.vn/student/question/DSA07017> 



#include <bits/stdc++.h>
using namespace std;
// Tìm chỉ số phần tử lớn hơn đầu tiên bên phải
vector<int> get_next_greater_index(const vector<int>& v, int n) {
    vector<int> next_index(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && v[i] >= v[st.top()]) {
            st.pop();
        }
        if(!st.empty()) next_index[i] = st.top();
        st.push(i);
    }
    return next_index;
}
// Tìm phần tử nhỏ hơn đầu tiên bên phải
vector<int> get_right_smaller_value(const vector<int>& v, int n) {
    vector<int> res(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && v[i] <= st.top()) {
            st.pop();
        }
        if(!st.empty()) res[i] = st.top();
        st.push(v[i]);
    }
    return res;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];
        vector<int> next_greater_index = get_next_greater_index(v, n);
        vector<int> right_smaller_value = get_right_smaller_value(v, n);
        for(int i = 0; i < n; ++i) {
            int j = next_greater_index[i];
            if(j == -1 || right_smaller_value[j] == -1)
                cout << -1 << " ";
            else
                cout << right_smaller_value[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}