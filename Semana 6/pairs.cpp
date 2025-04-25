#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll sum = accumulate(a.begin(), a.end(), 0LL);
    x -= sum;
    y -= sum;

    ll ans = 0;
    for (int i = 0; i < n-1; i++) {
        ll lo = - a[i] - y;
        ll hi = - a[i] - x;

        auto it1 = lower_bound(a.begin() + i + 1, a.end(), lo);
        auto it2 = upper_bound(a.begin() + i + 1, a.end(), hi);

        ans += distance(it1, it2);
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
