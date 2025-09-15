//From <https://code.ptit.edu.vn/student/question/DSA08018> 



#include <bits/stdc++.h>
using namespace std;
vector<string> v;
void kq(int n){
    queue<string> q;
    q.push("");
    while(!q.empty()){
        string top = q.front(); q.pop();
        if(top.size() > n) return;
        v.push_back(top);
        q.push(top + "6");
        q.push(top + "8");
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        v.clear();
        int n; cin >> n;
        kq(n);
        cout << v.size() - 1 << endl;
        for(int i = 1; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
