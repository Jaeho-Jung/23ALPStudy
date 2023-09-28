#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> radj;
vector<bool> visited;
int n, m, x;

void input() {
    cin >> n >> m >> x; x--;
    adj = vector<vector<int>>(n, vector<int>());
    radj = vector<vector<int>>(n, vector<int>());
    visited = vector<bool>(n, false);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
}

int DFS(int v, vector<vector<int>> &adj) {
    int ret = 1;
    for (int nxt : adj[v]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;
        ret += DFS(nxt, adj);
    }
    return ret;
}

void solve() {
    int ans_min = DFS(x, radj);
    int ans_max = n - DFS(x, adj) + 1;

    cout << ans_min << ' ' << ans_max;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    
    return 0;
}
