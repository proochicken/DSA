//From <https://code.ptit.edu.vn/student/question/DSA02007> 



#include <bits/stdc++.h>
using namespace std;
int k;
string max_str;
void ql(string& s, int k, int i){
    if(k == 0) return;
    char max_char = *max_element(s.begin() + i, s.end());
    if(max_char != s[i]) k--;
    for(int j = s.size() - 1; j >= i; j--){
            if(s[j] == max_char){
                swap(s[i], s[j]);
                if(s > max_str) max_str = s;
                ql(s, k, i + 1);
                swap(s[i], s[j]);
            }
    }
}

int main(){ 
    int t; cin >> t;
    while(t--){
        string s;
        cin >> k >> s;
        max_str = s;
        ql(s, k, 0);
        cout << max_str << endl;
    }
}
