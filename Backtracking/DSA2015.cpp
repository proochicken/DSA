//From <https://code.ptit.edu.vn/student/question/DSA02015> 


#include <bits/stdc++.h>
using namespace std;
bool check(string s){
    int count_char = 0, count_alpha = 0;
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])) count_alpha++;
        if(s[i] == '(') count_char++;
        else if(s[i] == ')'){
            count_char--;
            if(count_char < 0) return false;
        }
    }
    if(count_alpha == 1 && s.size() == 1) return false;
    if(s.empty()) return false;
    return count_char == 0;
}
void bfs(string s){
    set<string> res;
    set<string> visited;
    queue<string> q;
    bool found = false;
    q.push(s);
    visited.insert(s);
    while(!q.empty()){
        string cur = q.front(); q.pop();
        
        if(check(cur)){
            res.insert(cur);
            found = true;
        }
        if(found == true) continue;
        for(int i = 0; i < cur.size(); i++){
            if(cur[i] != '(' && cur[i] != ')') continue;
            
            string next = cur.substr(0, i) + cur.substr(i + 1);
            if(!visited.count(next)){
                visited.insert(next);
                q.push(next);
            }
        }
    }
    if(res.empty()) cout << -1;
    else{
        for(string x : res){
            cout << x << " ";
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        bfs(s);
        cout << endl;
    }
}