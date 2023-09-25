#include <iostream>
#include <cmath>

using namespace std;

int n, k;

void input() {
    cin >> n >> k;
}

int solve() {
    int bit, cnt  = 0;
    int pos = 0;
    for(bit = (int)log2(n); bit >= 0; bit--) {
        if (!((n>>bit) & 1)) continue;
        if (++cnt != k) continue;
        pos = bit;
    }
    if (cnt <= k)
        return 0;
    if (!((n>>(pos+1)) & 1))
        pos++; 
    return (1<<pos) - (((1<<pos)-1)&n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solve();
    
    return 0;
}
