#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    int n;

    while (t--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        int dp[n];
        dp[0] = max(0, a[0]);

        for (int i = 1; i < n; i++) {
            dp[i] = max(0, max(dp[i-1] + a[i], a[i]));
        }

        cout << dp[n-1] << endl;
    }

    return 0;
}