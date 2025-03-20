#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll maior_bit(ll num) {
    if (num == 0) return 0;
    ll msb = 0;
    while (num > 1) {
        num >>= 1;
        msb++;
    }
    return (1LL << msb);
}

ll xor_query(ll l, ll r) {
    ll out;
    printf("xor %lld %lld\n", l, r);
    fflush(stdout);
    scanf("%lld", &out);
    return out;
}

void bin_search(ll lo, ll hi, vector<ll>& ans) {
    ll mid;
    ll last_xor_r = -1;
    bool mesmo_bit = false;
    while (ans.size() < 2) {
        if (hi <= lo) {
            // cout << "Adding to vec: " << lo << " " << hi;
            ans.push_back(lo);
            return;
        }

        ll msb_r = maior_bit(hi);

        if (hi - lo == 1) {
            mid = hi;
        }
        else if (msb_r <= lo) {
            mid = (lo + hi) / 2;
            mesmo_bit = true;
        }
        else {
            mid = msb_r;
        }

        // cout << "Quering right: ";
        ll xor_r = xor_query(mid, hi);
        if (last_xor_r == -1) last_xor_r = xor_r;
        if (xor_r == 0) {
            hi = mid - 1;
        }

        else {
            if (!mesmo_bit) {
                // cout << "Quering left: ";
                ll xor_l = xor_query(lo, mid-1);
                if (xor_l == 0) {
                    lo = mid;
                }
                else {
                    bin_search(mid, hi, ans);
                    bin_search(lo, mid-1, ans);
                }
            }
            else if (last_xor_r != xor_r) {
                // cout << "Quering left: ";
                ll xor_l = xor_query(lo, mid-1);
                if (xor_l == 0) {
                    lo = mid;
                }
                else {
                    bin_search(mid, hi, ans);
                    bin_search(lo, mid-1, ans);
                }
            }
            lo = mid;
        }

        last_xor_r = xor_r;
    }
}

void solve(ll n) {
    ll total_xor = xor_query(1, n);
    vector<ll> ans;

    ll lo = 1; ll hi = n;
    bin_search(lo, hi, ans);

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
