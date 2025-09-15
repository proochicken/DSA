//From <https://code.ptit.edu.vn/student/question/DSA02030> 


#include <bits/stdc++.h>
using namespace std;
char c;
int k;
vector<char> v;
void in(vector<char>& cur){
    for(int i = 0; i < k; i++){
        cout << cur[i];
    }
    cout << endl;
}
void ql(char start, vector<char>& cur){
    if(cur.size() == k){
        in(cur);
        return;
    }
    for(char j = start; j <= c; j++){
        cur.push_back(j);
        ql(j, cur);
        cur.pop_back();
    }
}
int main(){
    cin >> c >> k;
    ql('A', v);
}
