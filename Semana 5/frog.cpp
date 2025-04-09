#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
    int n, k; cin >> n >> k;
    vector<ll> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<ll> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = LLONG_MAX;
        for (int j = max(0, i - k); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n-1];

    return 0;
}
