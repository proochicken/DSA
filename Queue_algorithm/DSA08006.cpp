//From <https://code.ptit.edu.vn/student/question/DSA08006> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int kq(){
    queue<string> q;
    q.push("9");
    while(!q.empty()){
        string top = q.front(); q.pop();
        ll x = stoll(top);
        if(x % n == 0) return x;
        q.push(top + "0");
        q.push(top + "9");
    }
    return 0;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        cout << kq() << endl;
    }
}
