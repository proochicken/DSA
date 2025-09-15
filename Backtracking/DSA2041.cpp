//From <https://code.ptit.edu.vn/student/question/DSA02041> 



#include <bits/stdc++.h>
using namespace std;
int n;
int bfs(int n){
    queue<pair<int, int>> q;
    set<int> visited;
    q.push({n, 0});
    visited.insert(n);
    while(!q.empty()){
        auto [val, step] = q.front(); q.pop();
        if(val == 1) return step;
        if(val - 1 > 0 && !visited.count(val - 1)){
            q.push({val - 1, step + 1});
            visited.insert(val - 1);
        }
        if(val % 2 == 0 && !visited.count(val / 2)){
            q.push({val / 2, step + 1});
            visited.insert(val / 2);
        }
        if(val % 3 == 0 && !visited.count(val / 3)){
            q.push({val / 3, step + 1});
            visited.insert(val / 3);
        }
    }
    return -1;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        cout << bfs(n) << endl;
    }
}
