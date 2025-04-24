#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
    ll n, m; cin >> n >> m;
    vector<ll> hotels(n);
    for (int i = 0; i < n; i++) {
        cin >> hotels[i];
    }

    vector<ll> pref(n);
    pref[0] = hotels[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + hotels[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int lo = i + 1; int hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            ll sum = pref[mid] - pref[i] + hotels[i];
            if (sum <= m) {
                j = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        ans = max(ans, pref[j] - pref[i] + hotels[i]);
    }

    cout << ans;
 
    return 0;
}
