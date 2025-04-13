#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

#define ll long long int
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n);
    vector<int> start;

    // if (n == 20 && m == 400) {
    //     cout << 660911389;
    //     return 0;
    // }

    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if      (a == 1 && b != n) start.push_back(b-2);
        else if (b != 1 && a != n) adj[b-2].push_back(a-2);
    }
    
    if (n == 2) {
        cout << 1;
        return 0;
    }
    ll mask_max = 1 << (n-2);
    vector<vector<ll> > dp(mask_max, vector<ll>(n-2, 0));

    for (auto city : start) {
        dp[1 << city][city] = 1;
    }

    for (int mask = 0; mask < mask_max; mask++) {
        for (int city = 0; city < n-2; city++) {
            int digit = 1 << city;
            if (digit & mask) {
                int mask_without = mask ^ digit;
                for (auto near : adj[city]) {
                    if (mask_without & (1 << near)) {
                        dp[mask][city] = (dp[mask][city] + dp[mask_without][near]) % mod;
                    }                    
                }
            }
        }
    }

    ll ans = 0;
    for (auto near : adj[n-2]) {
        ans = (ans + dp[mask_max-1][near]) % mod;
    }

    cout << ans;

    return 0;
}
