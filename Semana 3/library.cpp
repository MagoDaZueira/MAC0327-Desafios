#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll total_xor;

ll casas_binarias(ll num) {
    if (num == 0) return 0;
    ll conta = 0;
    while (num > 1) {
        num >>= 1;
        conta++;
    }
    return conta;
}

ll xor_query(ll l, ll r) {
    ll out;
    printf("xor %lld %lld\n", l, r);
    fflush(stdout);
    scanf("%lld", &out);
    return out;
}

void bin_search(ll lo, ll hi, vector<ll>& ans, ll xor_intervalo) {
    ll mid;
    ll potencia = casas_binarias(hi);
    while (ans.size() < 2) {
        if (hi <= lo) {
            ans.push_back(lo);
            return;
        }

        if (hi - lo == 1) mid = hi;
        else              mid = (lo + hi) / 2;

        ll xor_r = xor_query(mid, hi);

        if (xor_r == 0) {
            hi = mid - 1;
        }
        else if (xor_r != xor_intervalo) {
            ll casas_xor_r = casas_binarias(xor_r);

            if (casas_xor_r < potencia) {
                ll xor_l = xor_query(lo, mid-1);
                ans.push_back(xor_l);
                xor_intervalo ^= xor_l;
                lo = mid;
            }
            else {
                hi = mid - 1;
                xor_intervalo ^= xor_r;
                ans.push_back(xor_r);
            }
        }
        else {
            lo = mid;
        }
    }
}

void solve(ll n) {
    total_xor = xor_query(1, n);
    vector<ll> ans;

    vector<pair<ll, ll>> candidates;
    for (ll i = 1; i < n; i <<= 1) {
        ll out = xor_query(i, min((i << 1) - 1, n));
        if (out != 0) {
            candidates.push_back({i, out});
        }
    }

    if (candidates.size() == 3) {
        ans.push_back(candidates[0].second);
        ans.push_back(candidates[1].second);
    }
    
    else if (candidates.size() == 2) {
        ll i, out;
        if (casas_binarias(candidates[0].second) != casas_binarias(candidates[0].first)) {
            i = candidates[0].first;
            out = candidates[0].second;
            ans.push_back(candidates[1].second);
        }
        else {
            i = candidates[1].first;
            out = candidates[1].second;
            ans.push_back(candidates[0].second);
        }
        bin_search(i, min((i << 1) - 1, n), ans, out);
    }

    else {
        ll i = candidates[0].first;
        ll out = candidates[0].second;
        bin_search(i, min((i << 1) - 1, n), ans, out);
    }

    ll last_num = total_xor ^ ans[0] ^ ans[1];
    ans.push_back(last_num);
    printf("ans %lld %lld %lld\n", ans[0], ans[1], ans[2]);
    fflush(stdout);
}

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        solve(n);
    }

    return 0;
}
