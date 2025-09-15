//From <https://code.ptit.edu.vn/student/question/DSA02045> 

#include <bits/stdc++.h>
using namespace std;
string s;
int n;
vector<string> v;
void ql(int start, string& cur){
    for(int i = start; i < s.size(); i++){
        cur += s[i];
        v.push_back(cur);
        ql(i + 1, cur);
        cur.pop_back();
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        v.clear();
        cin >> n >> s;
        string tmp = "";
        ql(0, tmp);
        sort(v.begin(), v.end());
        for(string x : v) cout <<x << " ";
        cout << endl;
    }
}
