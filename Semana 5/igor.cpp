#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
const ll mod = 998244353;

ll prefix_range(vector<ll>& pref, int x, int d2, int lower) {
    int m = pref.size();
    int r2 = d2 - lower;
    int lo = max(0, (int)ceil(x - sqrt(r2)));
    int hi = min(m-1, (int)floor(x + sqrt(r2)));

    if (lo == 0) return pref[hi];
    return (pref[hi] - pref[lo - 1] + mod) % mod;
}

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    int d2 = d * d;

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(2, 0)));
    vector<ll> pref(m, 0);

    if (grid[n-1][0] == 'X') {
        dp[n-1][0][0] = 1;
        pref[0] = 1;
    }
    for (int j = 1; j < m; j++) {
        if (grid[n-1][j] == 'X') dp[n-1][j][0] = 1;
        pref[j] = (pref[j-1] + dp[n-1][j][0]) % mod;
    }

    for (int j = 0; j < m; j++) {
        if (grid[n-1][j] == 'X') {
            dp[n-1][j][1] = prefix_range(pref, j, d2, 0);
        }
    }

    pref[0] = dp[n-1][0][1];
    for (int j = 1; j < m; j++) {
        pref[j] = (pref[j-1] + dp[n-1][j][1]) % mod;
    }

    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                dp[i][j][0] = prefix_range(pref, j, d2, 1);
            }
        }
        pref[0] = dp[i][0][0];
        for (int j = 1; j < m; j++) {
            pref[j] = (pref[j-1] + dp[i][j][0]) % mod;
        }

        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                dp[i][j][1] = prefix_range(pref, j, d2, 0);
                dp[i][j][1] = (dp[i][j][1] - dp[i][j][0] + mod) % mod;
            }
        }

        int dp_sum = 0;
        for (int j = 0; j < m; j++) {
            dp_sum = (dp_sum + dp[i][j][1]) % mod;
            pref[j] = (pref[j] + dp_sum) % mod;
        }
    }

    ll ans = 0;

    for (int j = 0; j < m; j++) {
        ans = (ans + dp[0][j][0] + dp[0][j][1]) % mod;
    }

    cout << ans << endl;
}
 
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
