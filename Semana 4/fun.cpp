#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool possible(ll a, ll b, ll c, ll n, ll x) {
    bool cond1 = ((a * b) + (a * c) + (b * c)) <= n;
    bool cond2 = (a + b + c) <= x;
    return cond1 && cond2;
}

void solve() {
    ll n, x; cin >> n >> x;

    ll ans = 0;

    ll n2 = n / 2;
    for (int a = 1; a <= n2; a++) {
        ll lim_b = n / a;
        for (int b = 1; b <= lim_b; b++) {
            ll lo = 1, hi = x-2;
            ll max_c = 0;
            while (lo <= hi) {
                ll mid = (lo + hi) / 2;
                if (possible(a,b,mid,n,x)) {
                    max_c = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            ans += max_c;
        }
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();

    return 0;
}
