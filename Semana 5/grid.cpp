#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mod = 1e9 + 7;
 
int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    dp[0][0] = 1;
    for (int i = 1; i < h; i++) {
        if (grid[i][0] == '#') break;
        dp[i][0] = 1;
    }
    for (int i = 1; i < w; i++) {
        if (grid[0][i] == '#') break;
        dp[0][i] = 1;
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[h-1][w-1];

    return 0;
}
