//From <https://code.ptit.edu.vn/student/question/DSA02029> 



#include <iostream>
using namespace std;
// Hàm đệ quy (quay lui) di chuyển n đĩa từ cột A sang C dùng B làm trung gian
void Hanoi(int n, char A, char B, char C) {
    if (n == 0) return;
    // Bước 1: di chuyển n-1 đĩa từ A sang B (dùng C)
    Hanoi(n - 1, A, C, B);
    // Bước 2: di chuyển đĩa lớn nhất còn lại từ A sang C
    cout << A << " -> " << C << endl;
    // Bước 3: di chuyển n-1 đĩa từ B sang C (dùng A)
    Hanoi(n - 1, B, A, C);
}
int main() {
    int n;
    cin >> n;
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}
