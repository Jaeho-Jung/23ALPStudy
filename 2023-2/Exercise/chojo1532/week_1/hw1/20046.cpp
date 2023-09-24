#include <iostream>
#include <queue>

#define INF (1e9)

using namespace std;

struct Location {
    int r; int c;
    Location(int r, int c):r(r),c(c) {}
};

class cmp {
    public:
        bool operator() (pair<int,Location> l, pair<int,Location> r) {
            return l.first > r.first;
        }
};

vector<Location> directions = {
    {0, -1},
    {0,  1},
    {-1, 0},
    { 1, 0},
};
vector<vector<int>> map;
int n, m;

void input() {
    cin >> n >> m;
    map = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
}

bool isValid(int r, int c) {
    return !(r < 0 || c < 0 || r >= n || c >= m)
            && map[r][c] != -1;
}

int solve() {
    if (map[0][0] == -1) return -1;

    priority_queue<pair<int,Location>, vector<pair<int,Location>>, cmp> q;
    vector<vector<int>> cost{n, vector<int>(m, INF)};

    q.push({cost[0][0] = map[0][0], {0, 0}});

    while (!q.empty()) {
        auto [c, cur] = q.top(); q.pop();

        if (cur.r == n-1 && cur.c == m-1) break;

        for (Location d : directions) {
            int n_r = cur.r + d.r;
            int n_c = cur.c + d.c;
            if (!isValid(n_r, n_c)) continue;
            if (cost[n_r][n_c] > cost[cur.r][cur.c] + map[n_r][n_c]) {
                cost[n_r][n_c] = cost[cur.r][cur.c] + map[n_r][n_c];
                q.push({cost[n_r][n_c], {n_r, n_c}});
            }
        }
    }
    
    return cost[n-1][m-1] != INF ? cost[n-1][m-1] : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solve();
    
    return 0;
}
