//From <https://code.ptit.edu.vn/student/question/DSA02010> 



#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[25];
bool ok;
void in(vector<int>& cur){
    cout << "[";
    for(int i = 0; i < cur.size(); i++){
        cout << cur[i];
        if(i != cur.size() - 1) cout << " ";
    }
    cout << "] ";
    ok = true;
}
void ql(int s, int start, vector<int>& cur){
    for(int i = start; i < n; i++){
        if(s + a[i] <= x){
            cur.push_back(a[i]);
            if(s + a[i] == x){
                in(cur);
            } else {
                ql(s + a[i], i, cur); // tiếp tục dùng a[i]
            }
            cur.pop_back(); // backtrack
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n); // sắp xếp tăng dần
        vector<int> tmp;
        ok = false;
        ql(0, 0, tmp);
        if(!ok) cout << -1;
        cout << endl;
    }
}