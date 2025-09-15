//From <https://code.ptit.edu.vn/student/question/DSA02002> 



#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> v; // lưu tam giác
// Đệ quy sinh tam giác từ dưới lên
void build(vector<int> a) {
    v.push_back(a);
    if (a.size() == 1) return;
    vector<int> next;
    for (int i = 0; i < a.size() - 1; ++i) {
        next.push_back(a[i] + a[i + 1]);
    }
    build(next); // gọi đệ quy để sinh hàng tiếp theo
}
// In tam giác theo yêu cầu (từ trên xuống dưới, mỗi hàng trong [ ])
void print() {
    for (int i = v.size() - 1; i >= 0; --i) {
        cout << "[";
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j];
            if (j < v[i].size() - 1) cout << " ";
        }
        cout << "] ";
    }
    cout << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        v.clear();
        build(a);   // sinh tam giác
        print();    // in kết quả
    }
    return 0;
}

