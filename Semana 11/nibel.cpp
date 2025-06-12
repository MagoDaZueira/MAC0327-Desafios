#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int, int> pii;

const int MAXN = 300005;
const ll mod = 998244353;

vector<ll> dp(MAXN, -1);

ll expmod(ll x, ll ex, ll m) {
    if (ex == 0) return 1;

    ll half = expmod(x, ex / 2, m);
    half = (half * half) % m;

    if (ex % 2 == 0) return half;
    else return (half * x) % m;
}

ll modinv(ll x) {
    return expmod(x, mod - 2, mod);
}

ll fac(int n) {
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = (n * fac(n - 1)) % mod;
}

ll combination(int n, int k) {
    ll div = (fac(k) * fac(n - k)) % mod;
    return (fac(n) * modinv(div)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    map<int, int> increments;
    map<int, int> decrements;
    set<int> s;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        increments[a]++;
        decrements[b]++;
        s.insert(a);
        s.insert(b);
    }

    ll ans = 0;
    int active = 0;
    for (int x : s) {
        int inc = increments[x];
        for (int act = active; act < active + inc; act++) {
            if (act == k-1) ans = (ans + 1) % mod;
            else if (act >= k) {
                ans = (ans + combination(act, k-1)) % mod;
            }
        }
        active += inc - decrements[x];
    }

    cout << ans << endl;

    return 0;
}
