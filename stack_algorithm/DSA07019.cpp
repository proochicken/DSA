//From <https://code.ptit.edu.vn/student/question/DSA07019> 



#include <bits/stdc++.h>
using namespace std;
long long largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    long long max_area = 0;
    heights.push_back(0); // Thêm 0 vào cuối để xử lý các cột còn lại trong stack
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            long long height = heights[st.top()];
            st.pop();
            long long width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, height * width);
        }
        st.push(i);
    }
    heights.pop_back(); // Xóa phần tử 0 đã thêm vào (không bắt buộc)
    return max_area;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << largestRectangleArea(v) << "\n";
    }
    return 0;
}
