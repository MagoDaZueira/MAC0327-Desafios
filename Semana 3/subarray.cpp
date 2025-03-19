#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    vector<ll> pref0(n);
    vector<pair<ll, ll>> pref(n);
    pref0[0] = vec[0];
    pref[0] = {vec[0], 0};
    for (int i = 1; i < n; i++) {
        pref0[i] = pref0[i-1] + vec[i];
        pref[i] = {pref0[i], i};
    }

    sort(pref.begin(), pref.end());

    ll total = 0;
    for (ll i = 0; i < n; i++) {
        ll goal = x + pref0[i] - vec[i];
        auto it1 = lower_bound(pref.begin(), pref.end(), make_pair(goal, i));
        auto it2 = upper_bound(pref.begin(), pref.end(), make_pair(goal, LLONG_MAX));
        total += it2 - it1;
    }

    cout << total;
}
