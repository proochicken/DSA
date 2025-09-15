//From <https://code.ptit.edu.vn/student/question/DSA04007> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll k_to_dec(string s, int k){
    ll tmp = 1, ans = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        ans += tmp * (s[i] - '0');
        tmp *= k;
    }
    return ans;
}
void reverse_string(string& s){
    int l = 0, r = s.size() - 1;
    while(l <= r){
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++; r--;
    }
}
string dec_to_k(ll a, int k){
    string ans = "";
    while(a != 0){
        int x = a % k;
        ans += to_string(x);
        a /= k;
    }
    reverse_string(ans);
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        ll k, a, b; cin >> k >> a >> b;
        a = k_to_dec(to_string(a), k); b = k_to_dec(to_string(b), k);
        ll sum = a + b;
        cout << dec_to_k(sum, k) << endl;
    }
}
