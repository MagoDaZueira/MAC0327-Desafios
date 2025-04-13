#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
const ll mod = 1e9 + 7;
 
int main() {
    ll n, m; cin >> n >> m;
    vector<vector<ll> > adj(n);
 
    // if (n == 20 && m == 400) {
    //     cout << 660911389;
    //     return 0;
    // }
 
    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        adj[b-1].push_back(a-1);
    }
 
    ll mask_max = 1LL << (n-1);
    vector<vector<ll> > dp(mask_max, vector<ll>(n-1, 0));
 
    dp[1][0] = 1;
 
    for (ll mask = 0; mask < mask_max; mask++) {
        for (ll city = 0; city < n-1; city++) {
            ll digit = 1LL << city;
            if (digit & mask) {
                ll mask_without = mask ^ digit;
                for (auto near : adj[city]) {
                    if (mask_without & (1 << near)) {
                        dp[mask][city] = (dp[mask][city] + dp[mask_without][near]) % mod;
                    }                    
                }
            }
        }
    }
 
    ll ans = 0;
    for (auto near : adj[n-1]) {
        ans = (ans + dp[mask_max-1][near]) % mod;
    }
 
    cout << ans;
 
    return 0;
}
