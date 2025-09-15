//From <https://code.ptit.edu.vn/student/question/DSA11024> 



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Hàm trả về node gốc của cây nhị phân tìm kiếm cân bằng
int findRoot(vector<int>& a) {
    sort(a.begin(), a.end());         // Sắp xếp mảng tăng dần
    int mid = a.size() / 2;           // Lấy phần tử giữa
    if(a.size() % 2 == 0) mid -= 1;
    return a[mid];                    // Node gốc
}
int main() {
    int T;
    cin >> T;                         // Số lượng bộ test
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        cout << findRoot(a) << endl; // In node gốc của cây
    }
    return 0;
}
