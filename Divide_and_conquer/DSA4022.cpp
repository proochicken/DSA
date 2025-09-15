//From <https://code.ptit.edu.vn/student/question/DSA04022> 




#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char f[26];
void make_alphabet(){
    for(int i = 0; i < 26; i++){
        f[i] = char('A' + i);
    }
}
char find(int n, int k){
    if(n == 1) return 'A';
    if(k == pow(2, n - 1)) return f[n - 1];
    else if(k < pow(2, n - 1)) return find(n - 1, k);
    else return find(n - 1, k - (ll)pow(2, n - 1));
}
int main(){
    int t; cin >> t;
    make_alphabet();
    while(t--){
        int n, k; cin >> n >> k;
        cout << find(n, k) << endl;
    }
}