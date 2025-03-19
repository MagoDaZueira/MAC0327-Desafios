#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int lo = 2, hi = 999;
    ll mid1, mid2, ans, out;

    while (lo <= hi) {
        mid1 = lo + (hi - lo) / 3;
        mid2 = hi - (hi - lo) / 3;

        printf("? %lld %lld\n", mid1, mid2);
        fflush(stdout);
        scanf("%lld", &out);

        if (out == mid1 * mid2) {
            lo = mid2 + 1;
        }
        else if (out == mid1 * (mid2 + 1)) {
            lo = mid1 + 1;
            hi = mid2 - 1;
            ans = mid2;
        }
        else {
            ans = mid1;
            hi = mid1 - 1;
        }
    }

    printf("! %lld\n", ans);
    fflush(stdout);
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
