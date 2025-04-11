#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int VAL_MAX = 1e5 + 5;

int main() {
    int n, max_weight;
    cin >> n >> max_weight;

    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<ll> dp(VAL_MAX, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int v = VAL_MAX - 1; v >= values[i]; v--) {
            if (dp[v - values[i]] != LLONG_MAX) {
                dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
            }
        }
    }

    for (int v = VAL_MAX - 1; v >= 0; v--) {
        if (dp[v] <= max_weight) {
            cout << v << endl;
            break;
        }
    }

    return 0;
}