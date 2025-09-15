//From <https://code.ptit.edu.vn/student/question/DSA08004> 



#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int k; string s;
        cin >> k >> s;
        map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        priority_queue<int> q;
        for(auto x : mp){
            q.push(x.second);
        }
        while(!q.empty() && k != 0){
            int top = q.top(); q.pop();
            if(k != 0){
                k--;
                top--;
            }
            else break;
            q.push(top);
        }
        long long x = 0;
        while(!q.empty()){
            x += 1ll * q.top() * q.top(); q.pop();
        }
        cout << x << endl;
    }
}