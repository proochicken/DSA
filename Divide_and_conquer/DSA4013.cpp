//From <https://code.ptit.edu.vn/student/question/DSA04013> 



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        
        int res = N;
        int i = 0, j = N / 2;
        while (i < N / 2 && j < N) {
            if (A[i] * 2 <= A[j]) {
                res--;
                i++;
                j++;
            } else {
                j++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
