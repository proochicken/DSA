//From <https://code.ptit.edu.vn/student/question/DSA02001> 


#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> v;
void ql(vector<int>& cur){
    v.clear();
    v.push_back(cur);
    while(cur.size() > 1){
        vector<int> tmp;
        for(int i = 0; i < cur.size() - 1; i++){
            tmp.push_back(cur[i] + cur[i + 1]);
        }
        v.push_back(tmp);
        cur = tmp;
    }
}
void in(){
    for(auto row : v){
        cout << "[";
        for(int i = 0; i < row.size(); i++){
            cout << row[i];
            if(i != row.size() - 1) cout << " ";
        }
        cout << "]" << endl;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        vector<int> a;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a.push_back(x);
        }
        ql(a);
        in();
    }
}
