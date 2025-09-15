//From <https://code.ptit.edu.vn/student/question/DSA_P097> 



#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
using pii = pair<int, int>;
int bfs(pii start, pii end, const set<pii>& valid_cells) {
    queue<pair<pii, int>> q;
    set<pii> visited;
    q.push({start, 0});
    visited.insert(start);
    while (!q.empty()) {
        auto [cur, dist] = q.front(); q.pop();
        if (cur == end) return dist;
        for (int i = 0; i < 8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            pii next = {nx, ny};
            if (valid_cells.count(next) && !visited.count(next)) {
                visited.insert(next);
                q.push({next, dist + 1});
            }
        }
    }
    return -1;  // không tìm được đường đi
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int xA, yA, xB, yB, N;
        cin >> xA >> yA >> xB >> yB >> N;
        set<pii> valid_cells;
        for (int i = 0; i < N; i++) {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int y = y1; y <= y2; y++) {
                valid_cells.insert({x, y});
            }
        }
        cout << bfs({xA, yA}, {xB, yB}, valid_cells) << endl;
    }
}