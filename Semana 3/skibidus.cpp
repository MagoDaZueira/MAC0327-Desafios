#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(ll n, vector<ll>& a, vector<ll>& b) {
    sort(b.begin(), b.end());
    ll last = min(a[0], b[0] - a[0]);

    for (int i = 1; i < n; i++) {
        ll goal = last + a[i];
        auto it = lower_bound(b.begin(), b.end(), goal);
        
        if (it == b.end()) {
            if (a[i] < last) {
                cout << "NO" << endl;
                return;
            }
            last = a[i];
        }
        else {
            ll new_a = *it - a[i];
            if (a[i] < new_a && a[i] >= last) last = a[i];
            else                              last = new_a;
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        solve(n, a, b);
    }

    return 0;
}
