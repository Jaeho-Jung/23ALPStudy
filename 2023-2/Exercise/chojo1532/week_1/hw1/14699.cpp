#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int v; int w;
    Node(int v=0, int w=0):v(v), w(w) {}
};

bool cmp(const Node &l, const Node &r) {
    return l.w > r.w;
}

vector<Node> nodes;
vector<vector<int>> adj;
vector<int> ans;
int n, m;

void input() {
    cin >> n >> m;
    nodes = vector<Node>(n);
    adj = vector<vector<int>>(n, vector<int>());
    ans = vector<int>(n, 0);
    int w;
    for (int v = 0; v < n; v++) {
        cin >> w;
        nodes[v] = {v, w};
    }
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v; u--; v--;
        if (nodes[u].w < nodes[v].w)
            swap(u, v);
        adj[u].push_back(v);
    }
}

void visit(Node s) {
    if (ans[s.v] >= 1) return;

    queue<int> q;
    q.push(s.v);
    ans[s.v] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (ans[nxt] >= ans[cur]+1) continue;
            ans[nxt] = ans[cur]+1;
            q.push({nxt});
        }
    }
}

void solve() {
    sort(begin(nodes), end(nodes), cmp);

    for (Node node : nodes)
        visit(node);
    for (int v = 0; v < n; v++)
        cout << ans[v] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    
    return 0;
}
