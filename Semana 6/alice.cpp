#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int next_pos(int pivot, ll v, vector<ll>& a, vector<ll>& pref, bool to_left) {
    int lo, hi, mid;
    if (to_left) {
        lo = 0;
        hi = pivot;
    }
    else {
        lo = pivot;
        hi = a.size() - 1;
    }
    
    ll ans = -1;
    ll sum;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (to_left) sum = pref[pivot] - pref[mid] + a[mid];
        else         sum = pref[mid] - pref[pivot] + a[pivot];

        if (sum >= v) {
            ans = mid;
            if (to_left) lo = mid + 1;
            else         hi = mid - 1;
        }
        else {
            if (to_left) hi = mid - 1;
            else         lo = mid + 1;
        }
    }

    return ans;
}

void solve() {
    ll n, m, v; cin >> n >> m >> v;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + a[i];
    }

    vector<int> right(m+1);
    vector<int> left(m+1);

    right[m] = n-1;
    for (int i = m-1; i >= 0; i--) {
        right[i] = next_pos(right[i+1], v, a, pref, true) - 1;
        if (right[i] < -1 || (i != 0 && right[i] < 0)) { cout << -1 << endl; return; }
    }
    left[0] = 0;
    for (int i = 1; i <= m; i++) {
        left[i] = next_pos(left[i-1], v, a, pref, false) + 1;
        if (left[i] > n || (i != m && left[i] >= n)) { cout << -1 << endl; return; }
    }

    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        if      (i == 0 && right[0] == -1) continue;
        else if (i == m && left[m] == n)   continue;

        ll temp = pref[right[i]] - pref[left[i]] + a[left[i]];
        ans = max(ans, temp);
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
