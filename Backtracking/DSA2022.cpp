//From <https://code.ptit.edu.vn/student/question/DSA02022> 



#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string s(8, '0');
void check(){
    int day = stoi(s.substr(0, 2));
    int month = stoi(s.substr(2, 2));
    int year = stoi(s.substr(4, 4));
    if(day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 2000){
        string tmp = s;
        tmp.insert(2, "/");
        tmp.insert(5, "/");
        v.push_back(tmp);
    }
}
void ql(int i){
    if(i == 8){
        check();
        return;
    }
    s[i] = '0';
    ql(i + 1);
    s[i] = '2';
    ql(i + 1);
}
int main(){
    ql(0);
    sort(v.begin(), v.end());
    for(string s : v){
        cout << s << endl;
    }
}
