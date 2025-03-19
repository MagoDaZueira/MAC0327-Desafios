#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int maior_bit(int num) {
    if (num == 0) return 0;
    int msb = 0;
    while (num > 1) {
        num >>= 1;
        msb++;
    }
    return (1 << msb);
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
    while (ans.size() < 2) {
        if (hi <= lo) {
            ans.push_back(lo);
            return;
        }

        ll msb_r = maior_bit(hi);
        ll msb_l = maior_bit(lo);

        if      (hi - lo == 1)   mid = hi;
        else if (msb_l == msb_r) mid = (lo + hi) / 2;
        else                     mid = msb_r;

        // cout << "Quering right: ";
        ll xor_r = xor_query(mid, hi);
        if (xor_r == 0) {
            hi = mid - 1;
        }
        else {
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
    }
}

void solve(int n) {
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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        solve(n);
    }

    return 0;
}


// Para cada intervalo [l, r], separa ele em 2:
// [mid, r]: números com o bit mais significativo fixo (maior bit de r)
// [l, mid - 1]: o resto
//
// Se der 0 na direita, busca na esquerda
// Se der !=0 na direita, pergunta na esquerda:
//    se der == 0, busca na direita
//    se der != 0, busca na esquerda e na direita
//
// Se o bit mais significativo de l e r for o mesmo,
// fazemos busca binária normal, e é garantido que !=0 <=> tem uma resposta