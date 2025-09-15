//From <https://code.ptit.edu.vn/student/question/DSA10004> 



#include <bits/stdc++.h>
using namespace std;
int degree[1005];
int main(){
    int T; cin >> T;
    while(T--){
        int V, E;
        cin >> V >> E;
        // reset degree array
        memset(degree, 0, sizeof(degree));
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
        }
        int odd = 0;
        for(int i = 1; i <= V; i++){
            if(degree[i] % 2 != 0) odd++;
        }
        if(odd == 0) cout << "2\n";       // Chu trình Euler
        else if(odd == 2) cout << "1\n";  // Đường đi Euler
        else cout << "0\n";               // Không tồn tại
    }
    return 0;
}