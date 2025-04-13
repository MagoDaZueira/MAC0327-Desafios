#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
const ll mod = 1e9 + 7;
 
int main() {
    int n; cin >> n;
    vector<vector<ll> > likes(n);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            if (a == 1) likes[i].push_back(j);
        }
    }
 
    int mask_max = 1 << n;
    vector<vector<ll> > dp(mask_max, vector<ll>(n, 0));

    for (auto woman : likes[0]) {
        dp[1 << woman][0] = 1;
    }
 
    for (int man = 1; man < n; man++) {
        for (int mask = 0; mask < mask_max; mask++) {
            if (man+1 != __builtin_popcount(mask)) continue;
            for (auto woman : likes[man]) {
                int bit = 1 << woman;
                if (bit & mask) {
                    dp[mask][man] = (dp[mask][man] + dp[mask ^ bit][man-1]) % mod;
                }
            }
        }
    }
 
    cout << dp[mask_max-1][n-1];
 
    return 0;
}
