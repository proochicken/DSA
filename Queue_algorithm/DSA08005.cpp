//From <https://code.ptit.edu.vn/student/question/DSA08005> 



#include <bits/stdc++.h>
using namespace std;
int n;
void kq(){
    queue<string> q;
    q.push("1");
    int cnt = 0;
    while(!q.empty()){
        if(cnt >= n) return;
        string top = q.front(); q.pop();
        cout << top << " ";
        cnt++;
        q.push(top + "0");
        q.push(top + "1");
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        kq();
        cout << endl;
    }
}
