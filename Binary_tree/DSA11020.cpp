//From <https://code.ptit.edu.vn/student/question/DSA11020> 



#include <bits/stdc++.h>
using namespace std;
bool isInorderBST(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << (isInorderBST(A) ? 1 : 0) << endl;
    }
    return 0;
}
