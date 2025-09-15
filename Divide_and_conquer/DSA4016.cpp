//From <https://code.ptit.edu.vn/student/question/DSA04016> 



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void merge(int a[], int m, int b[], int n, vector<int>& v){
    int i = 1, j = 1;
    while(i <= m && j <= n){
        if(a[i] <= b[j]){
            v.push_back(a[i]);
            i++;
        }
        else{
            v.push_back(b[j]);
            j++;
        }
    }
    while(i <= m){
        v.push_back(a[i]);
        i++;
    }
    while(j <= n){
        v.push_back(b[j]);
        j++;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int m, n, k; cin >> m >> n >> k;
        int a[m + 1], b[n + 1];
        for(int i = 1; i <= m; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        vector<int> res;
        merge(a, m, b, n, res);
        cout << res[k - 1] << endl;
    }
}