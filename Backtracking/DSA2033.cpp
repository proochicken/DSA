//From <https://code.ptit.edu.vn/student/question/DSA02033> 



#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
string s;
bool used[15];
void ql(int i, string cur){
    if(cur.size() == n){
        v.push_back(cur);
        return;
    }
    for(int j = 1; j <= n; j++){
        if(!used[j]){
            if(i == 0 || abs(j - (cur[i - 1] - '0')) != 1){
                used[j] = true;
                ql(i + 1, cur + to_string(j));
                used[j] = false;
            }
        }
    }
}
void in(){
    sort(v.begin(), v.end());
    for(string s : v) cout << s << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        v.clear();
        memset(used, false, sizeof(used));
        cin >> n;
        ql(0, "");
        in();
    }
}
