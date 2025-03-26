#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mod = 1e9 + 7;
const ll phi_mod = mod - 1;

ll expmod(ll x, ll ex, ll m) {
    if (ex == 0) return 1;

    ll half = expmod(x, ex / 2, m);
    half = (half * half) % m;

    if (ex % 2 == 0) return half;
    else return (half * x) % m;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    b %= phi_mod;
    a %= mod;

    ll seq_amount = expmod(b, c, phi_mod);
    ll total = expmod(a, seq_amount, mod);

    cout << total << endl;
}

int main() {
    int n; cin >> n;
    while (n--) solve();

    return 0;
}
