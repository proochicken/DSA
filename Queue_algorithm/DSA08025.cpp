//From <https://code.ptit.edu.vn/student/question/DSA08025> 



#include <bits/stdc++.h>
using namespace std;
int si, sj, ti, tj;
bool visited[25][25];
map<char, int> mp;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
void char_to_int(){
    int cnt = 1;
    for(char c = 'a'; c <= 'h'; c++){
        mp[c] = cnt;
        cnt++;
    }
}
int bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{si, sj}, 0});
    visited[si][sj] = true;
    while(!q.empty()){
        auto top = q.front(); q.pop();
        int x = top.first.first, y = top.first.second, z = top.second;
        if(x == ti && y == tj) return z;
        for(int i = 0; i < 8; i++){
            int i1 = x + dx[i], j1 = y + dy[i];
            if(i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && !visited[i1][j1]){
                visited[i1][j1] = true;
                q.push({{i1, j1}, z + 1});
            }
        }
    }
    return 0;
}
int main(){
    int t; cin >> t;
    char_to_int();
    while(t--){
        memset(visited, false, sizeof(visited));
        string s1, s2; cin >> s1 >> s2;
        si = s1[1] - '0'; sj = mp[s1[0]];
        ti = s2[1] - '0'; tj = mp[s2[0]];
        cout << bfs() << endl;
    }
}
