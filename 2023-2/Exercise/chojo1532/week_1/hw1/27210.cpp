#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> arr, sum[2];

void input() {
    cin >> n;
    arr = vector<int>(n+1, 0);
    for (int i = 0; i < 2; i++)
        sum[i] = vector<int>(n+1, 0);

    int v;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        arr[i] = (v-1.5)*2;
    }
}

int solve() {
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        sum[0][i] = max(sum[0][i-1]-arr[i], 0);
        sum[1][i] = max(sum[1][i-1]+arr[i], 0); 
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, max(sum[0][i], sum[1][i]));

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solve();
    
    return 0;
}