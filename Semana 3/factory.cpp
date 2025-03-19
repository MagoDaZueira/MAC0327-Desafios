#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n, t; cin >> n >> t;
    vector<ll> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    ll lo = 1, hi = 1e18 + 2;
    ll mid, ans;

    while (lo <= hi) {
        mid = (lo + hi) / 2;

        ll products = 0;
        for (int i = 0; i < n; i++) {
            if (products >= t) break;
            products += mid / times[i];
        }

        if (products >= t) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
