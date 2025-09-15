//From <https://code.ptit.edu.vn/student/question/DSA10005> 



#include <bits/stdc++.h>
using namespace std;
int inDeg[1005], outDeg[1005];
int main(){
    int T; cin >> T;
    while(T--){
        int V, E;
        cin >> V >> E;
        // Reset mảng
        memset(inDeg, 0, sizeof(inDeg));
        memset(outDeg, 0, sizeof(outDeg));
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            outDeg[u]++;
            inDeg[v]++;
        }
        bool ok = true;
        for(int i = 1; i <= V; i++){
            if(inDeg[i] != outDeg[i]){
                ok = false;
                break;
            }
        }
        cout << (ok ? 1 : 0) << endl;
    }
    return 0;
}
