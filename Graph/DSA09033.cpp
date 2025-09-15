//From <https://code.ptit.edu.vn/student/question/DSA09033> 



#include <bits/stdc++.h>
using namespace std;
int parent[100005], sz[100005];
int edge_count[100005]; // Đếm số cạnh trong mỗi thành phần liên thông
void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
        edge_count[i] = 0;
    }
}
int Find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) {
        edge_count[u]++; // Tăng số cạnh nếu cùng thành phần
        return;
    }
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    edge_count[u] += edge_count[v] + 1; // Cộng số cạnh của cả hai thành phần
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        init(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        }
        bool is_perfect = true;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) { // Nếu là đại diện của thành phần liên thông
                int k = sz[i];
                int required_edges = k * (k - 1) / 2;
                if (edge_count[i] != required_edges) {
                    is_perfect = false;
                    break;
                }
            }
        }
        cout << (is_perfect ? "YES" : "NO") << '\n';
    }
    return 0;
}
