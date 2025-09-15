//From <https://code.ptit.edu.vn/student/question/DSA02034> 

#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
bool used[15];
void ql(string cur, int i){
    if(cur.size() == n){
        v.push_back(cur);
        return;
    }
    for(int j = 1; j <= n; j++){
        if(!used[j]){
            if(abs(j - (cur[i - 1] - '0')) != 1 || i == 0){
                used[j] = true;
                ql(cur + to_string(j), i + 1);
                used[j] = false;
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        v.clear();
        memset(used, false, sizeof(used));
        ql("", 0);
        sort(v.begin(), v.end());
        for(string s : v) cout << s << endl;
    }
}
