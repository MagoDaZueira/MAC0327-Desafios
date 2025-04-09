#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<ll> dp(n+1, LLONG_MAX);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp != 0) {
            int digit = temp % 10;
            if (i - digit >= 0 && digit != 0) dp[i] = min(dp[i], 1 + dp[i - digit]);
            temp /= 10;
        }
    }

    cout << dp[n];

    return 0;
}
