//From <https://code.ptit.edu.vn/student/question/DSA08008> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int kq(int n){
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll top = q.front(); q.pop();
        if(top % n == 0) return top;
        q.push(top* 10 + 0);
        q.push(top* 10 + 1);
    }
    return 0;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << kq(n) << endl;
    }
}
