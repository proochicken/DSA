//From <https://code.ptit.edu.vn/student/question/DSA02003> 



#include <bits/stdc++.h>
using namespace std;
int n, a[15][15];
vector<string> v;
void ql(int i, int j, string s){
    if(i == n && j == n){
        v.push_back(s);
        return;
    }
    // Di chuyển xuống dưới (D)
    if(i + 1 <= n && a[i+1][j] == 1){
        ql(i + 1, j, s + 'D');
    }
    // Di chuyển sang phải (R)
    if(j + 1 <= n && a[i][j + 1] == 1){
        ql(i, j + 1, s + 'R');
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        v.clear();
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        if(a[1][1] == 1 && a[n][n] == 1){ // Kiểm tra điểm đầu và điểm đích
            ql(1, 1, "");
        }
        if(v.empty()){
            cout << -1 << endl;
        } else {
            sort(v.begin(), v.end()); // In theo thứ tự từ điển
            for(string s : v){
                cout << s << " ";
            }
            cout << endl;
        }
    }
}