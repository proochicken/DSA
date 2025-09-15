//From <https://code.ptit.edu.vn/student/question/DSA04011> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll bin_to_dec(string s){
    ll ans = 0, tmp = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        ans += tmp * (s[i] - '0');
        tmp *= 2;
    }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        ll a = bin_to_dec(s1), b = bin_to_dec(s2);
        cout << a * b << endl;
    }
}

