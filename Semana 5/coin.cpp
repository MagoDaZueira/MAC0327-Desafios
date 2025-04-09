#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mod = 1e9 + 7;
 
int main() {
    int n, x; cin >> n >> x;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto coin : coins) {
            if (i - coin >= 0) dp[i] = (dp[i] + dp[i - coin]) % mod;
        }
    }

    cout << dp[x];

    return 0;
}
