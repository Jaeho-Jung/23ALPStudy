#include <iostream>

using namespace std;

int N, L;

void input() {
    cin >> N >> L;
}

void solve() {
    int l = N>>1, r = l+1;
    int sum = l + r;

    while (l <= r && l >= 0 && r >= 0) {
        if (sum > N)
            sum -= r--;
        else if (sum < N)
            sum += --l;
        else {
            if (r-l+1 < L)
               sum += --l;
            else
                break;
        }
    }
    if (r - l + 1 > 100 || l < 0 || r < 0)
        cout << -1;
    else {
        for (int i = l; i <= r; i++)
            cout << i << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    
    return 0;
}
