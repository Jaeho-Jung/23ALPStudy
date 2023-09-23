#include <iostream>
#include <vector>
#include <algorithm>

#define INF (1e9)

using namespace std;

vector<int> P, Q;
int n, m, c1, c2;

void input() {
    cin >> n >> m;
    cin >> c1 >> c2;
    P = vector<int>(n);
    Q = vector<int>(m);
    for (int i = 0; i < n; i++)
        cin >> P[i];
    for (int i = 0; i < m; i++)
        cin >> Q[i];
}


pair<int, int> solve() {
    sort(begin(P), end(P));
    sort(begin(Q), end(Q));

    int pi = 0, qi = 0;

    int minimum = abs(P[pi] - Q[qi]);
    int cnt = 1;
    while (pi < n-1 || qi < m-1) {
        int d;
        if (pi+1 == n)
            d = abs(P[pi] - Q[++qi]);
        else if (qi+1 == m)
            d = abs(P[++pi] - Q[qi]);
        else {
            int d1 = abs(P[pi+1] - Q[qi]);
            int d2 = abs(P[pi] - Q[qi+1]);
            if (d1 > d2) {
                d = d2;
                qi++;
            }
            else {
                d = d1;
                pi++;
            }
        }
        if (minimum >= d) {
            cnt = minimum == d ? cnt+1 : 1;
            minimum = d;
        }
    }

    return {minimum + abs(c1-c2), cnt};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    auto ans = solve();
    cout << ans.first << ' ' << ans.second;
    
    return 0;
}
