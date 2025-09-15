//From <https://code.ptit.edu.vn/student/question/DSA02024> 



#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<string> res;
void in(vector<int>& cur){
    string tmp = "";
    for(int i = 0; i < cur.size(); i++){
        tmp += to_string(cur[i]) + " ";
    }
    res.push_back(tmp);
}
void ql(int start, vector<int>& cur){
    for(int i = start; i < n; i++){
        if (cur.empty() || cur.back() < v[i]) {
            cur.push_back(v[i]);
            if (cur.size() >= 2) {
                in(cur);
            }
            ql(i + 1, cur);
            cur.pop_back();
        }
    }
}
int main(){
    // int t; cin >> t;
    // while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        vector<int> tmp;
        ql(0, tmp);
        sort(res.begin(), res.end());
        for(string s : res){
            cout << s << endl;
        }
    // }
}
