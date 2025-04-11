#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string a, b, c; cin >> a >> b >> c;
    int na = a.size();
    int nb = b.size();

    vector<vector<int>> dp(na+1, vector<int>(nb+1, INT_MAX));

    dp[0][0] = 0;

    for (int i = 1; i <= na; i++) {
        if (c[i-1] == a[i-1]) dp[i][0] = dp[i-1][0];
        else                  dp[i][0] = dp[i-1][0] + 1;
    }
    for (int i = 1; i <= nb; i++) {
        if (c[i-1] == b[i-1]) dp[0][i] = dp[0][i-1];
        else                  dp[0][i] = dp[0][i-1] + 1;
    }

    for (int i = 1; i <= na; i++) {
        for (int j = 1; j <= nb; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + (a[i-1] != c[i + j - 1]));
            dp[i][j] = min(dp[i][j], dp[i][j-1] + (b[j-1] != c[i + j - 1]));
        }
    }

    cout << dp[na][nb] << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
