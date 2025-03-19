#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int lo = 2, hi = 999;
    ll mid, ans, out;

    while (lo <= hi) {
        mid = (lo + hi) / 2;

        printf("? %lld %lld\n", mid, mid);
        fflush(stdout);
        scanf("%lld", &out);

        if (out == mid * mid) {
            lo = mid + 1;
        }
        else {
            ans = mid;
            hi = mid - 1;
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
