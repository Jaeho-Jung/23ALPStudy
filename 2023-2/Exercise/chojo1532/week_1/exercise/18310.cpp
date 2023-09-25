#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF (1e9)

using namespace std;

vector<int> vec;
vector<int> acc;
int n;

void input() {
    cin >> n;
    vec = vector<int>(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
}

int solve() {
    sort(begin(vec), end(vec));
    return vec[ceil(n/2.0)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solve();
    
    
    return 0;
}
