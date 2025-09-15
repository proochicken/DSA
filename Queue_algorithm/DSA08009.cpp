//From <https://code.ptit.edu.vn/student/question/DSA08009> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool used[100005];
ll bfs(int s, int t){
    if(s >= t) return s - t;
    queue<pair<int, int>> q;
    q.push({s, 0});
    used[s] = true;
    while(!q.empty()){
        auto top = q.front(); q.pop();
        if(top.first == t) return top.second;
        if(top.first - 1 >= 0 && !used[top.first - 1]){
            used[top.first - 1] = true;
            q.push({top.first - 1, top.second + 1});
        }
        if(top.first * 2 <= 100000 && !used[top.first * 2]){
            used[top.first * 2] = true;
            q.push({top.first * 2, top.second + 1});
        }
    }
    return -1;
}
int main(){
    int q; cin >> q;
    while(q--){
        memset(used,false, sizeof(used));
        int s, t;
        cin >> s >> t;
        cout << bfs(s, t) << endl;
    }
}