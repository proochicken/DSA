//From <https://code.ptit.edu.vn/student/question/DSA11028> 



#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
vector<int> adj[MAX];
bool visited[MAX];
int dist[MAX];
int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    int max_dist = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                max_dist = max(max_dist, dist[v]);
                q.push(v);
            }
        }
    }
    return max_dist;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // Xóa dữ liệu cũ
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
            dist[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Bắt đầu từ gốc là 1
        cout << bfs(1) << endl;
    }
    return 0;
}
