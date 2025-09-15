//From <https://code.ptit.edu.vn/student/question/DSA07028> 



#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> stockSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }
        st.push(i);
    }
    return span;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> prices(N);
        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
        }
        vector<int> result = stockSpan(prices);
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}