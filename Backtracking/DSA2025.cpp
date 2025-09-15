//From <https://code.ptit.edu.vn/student/question/DSA02025> 



#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
bool used[15];
int min_lap = INT_MAX;

int count_lap(string& s1, string& s2){
    int freq[30] = {0};
    for(char c : s1) freq[c - 'A'] = 1;
    int cnt = 0;
    for(char c : s2){
        if(freq[c - 'A']){
            cnt++;
        }
    }
    return cnt;
}

void ql(int i, int tong_lap_hien_tai, vector<string>& cur){
    if(tong_lap_hien_tai >= min_lap){
        return; //Cat nhanh luon
    }
    if(cur.size() == n){
        min_lap = tong_lap_hien_tai;
        return;
    }
    for(int j = 0; j < n; j++){
        if(!used[j]){
            used[j] = true;
            cur.push_back(v[j]);
            int add = 0;
            if(i - 1 >= 0)
                add = count_lap(cur[i - 1], cur[i]);
            ql(i + 1, tong_lap_hien_tai + add, cur);
            used[j] = false;
            cur.pop_back();
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    vector<string> tmp;
    ql(0, 0, tmp);
    cout << min_lap;
}
