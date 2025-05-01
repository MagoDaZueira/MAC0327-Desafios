#include <bits/stdc++.h>
#define ll long long int
using namespace std;

unsigned int largest;
int n, m;
const int MAX_N = 100;
const int MAX_M = 100;
vector<vector<unsigned int>> a(MAX_N, vector<unsigned int>(MAX_M));
vector<vector<unordered_map<int, int>>> dp(MAX_N, vector<unordered_map<int, int>>(MAX_M));

void reset_dp(int n, int m) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dp[i][j].clear();
}

int dfs(int i, int j, unsigned int divisor) {
    if (divisor <= largest) return 1;

    if (i == n-1 && j == m-1) {
        largest = max(largest, divisor);
        return divisor;
    }

    int dp_val = dp[i][j][divisor];
    if (dp_val != 0) return dp_val;

    int res = 1;
    if (i+1 < n && a[i+1][j] > largest) res = max(res, dfs(i+1, j, __gcd(divisor, a[i+1][j])));
    if (j+1 < m && a[i][j+1] > largest) res = max(res, dfs(i, j+1, __gcd(divisor, a[i][j+1])));
    
    return dp[i][j][divisor] = res;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    reset_dp(n, m);

    largest = 0;
    int ans = dfs(0, 0, a[0][0]);
    cout << ans << endl;
    
    return;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
