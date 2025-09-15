//https://code.ptit.edu.vn/student/question/DSA01024

#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> v;
set<string> se;
void in(vector<string> cur){
    for(string s : cur){
        cout << s << " ";
    }
    cout << endl;
}
void ql(int start, vector<string> cur){
    if(cur.size() == k){
        in(cur);
        return;
    }
    for(int i = start; i < v.size(); i++){
        cur.push_back(v[i]);
        ql(i + 1, cur);
        cur.pop_back();
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        se.insert(s);
    }
    for(string s : se){
        v.push_back(s);
    }
    ql(0, {});
}
