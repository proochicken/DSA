//From <https://code.ptit.edu.vn/student/question/DSA02014> 


#include <bits/stdc++.h>
using namespace std;
int k, m, n;
vector<string> v;
char a[5][5];
bool visited[5][5];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
set<string> res;
void dfs(string cur, int i, int j){
    for(string s : v){
        if(cur == s){
            res.insert(cur);
        }
    }
    visited[i][j] = true;
    for(int k = 0; k < 8; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1]){
            cur += a[i1][j1];
            visited[i1][j1] = true;
            dfs(cur, i1, j1);
            visited[i1][j1] = false;
            cur.pop_back();
        }
    }
    visited[i][j] = false;
}
    
int main(){
    int t; cin >> t;
    while(t--){
        v.clear();
        res.clear();
        cin >> k >> n >> m;
        for(int i = 1; i <= k; i++){
            string s; cin >> s;
            v.push_back(s);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                memset(visited, false, sizeof(visited));
                dfs(string(1, a[i][j]), i, j);
            }
        }
        
        if(res.empty()) cout << -1 << endl;
        else{
            for(string s : res) cout << s << " ";
            cout << endl;
        }
    }
}
