#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
    int n, m; cin >> n >> m;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<int> dp(m+1, INT_MIN);
    vector<int> diff(m+1, 0);
    dp[0] = 0;

    int pontos = 0;
    for (int i = 0; i < n; i++) {
        if (r[i] > 0) {
            diff[r[i]]++;
        }
        else if (r[i] < 0) {
            if (pontos + r[i] + 1 < 0) continue;
            diff[0]++;
            diff[pontos + r[i] + 1]--;
        }
        else {
            int add = 0;
            for (int j = 0; j <= m; j++) {
                add += diff[j];
                dp[j] += add;
            }
            for (int smart = m; smart > 0; smart--) {
                dp[smart] = max(dp[smart], dp[smart-1]);
            }

            pontos++;
            fill(diff.begin(), diff.end(), 0);
        }
    }

    int add = 0;
    for (int j = 0; j <= m; j++) {
        add += diff[j];
        dp[j] += add;
    }

    int ans = dp[0];
    for (int i = 1; i <= m; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
 
    return 0;
}
