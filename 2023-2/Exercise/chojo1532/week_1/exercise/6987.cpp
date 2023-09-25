#include <iostream>
#include <vector>

using namespace std;

struct Game {
    int win;
    int draw;
    int lose;
    Game(int w=0, int d=0, int l=0):win(w),draw(d),lose(l) {}
};

vector<Game> games;
vector<Game> sim;
vector<pair<int,int>> match;

void input() {
    games = vector<Game>(6);
    sim = vector<Game>(6);
    
    for (int i = 0; i < 6; i++) {
        cin >> games[i].win >> games[i].draw >> games[i].lose;
    }
}

bool solve(int n = 0) {
    if (n == 15) {
        for (int i = 0; i < 6; i++) {
            if (sim[i].win != games[i].win ||
                sim[i].draw != games[i].draw ||
                sim[i].lose != games[i].lose)
                return false;
        }
        return true;
    }
    int ret = false;
    auto [home, away] = match[n];

    sim[home].win++;sim[away].lose++;
    ret |= solve(n+1);
    sim[home].win--;sim[away].lose--;

    sim[home].lose++;sim[away].win++;
    ret |= solve(n+1);
    sim[home].lose--;sim[away].win--;

    sim[home].draw++;sim[away].draw++;
    ret |= solve(n+1);
    sim[home].draw--;sim[away].draw--;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++)
        for (int j = i+1; j < 6; j++)
            match.push_back({i, j});

    for (int i = 0; i < 4; i++) {
        input();
        cout << solve() << ' ';    
    }
    return 0;
}
