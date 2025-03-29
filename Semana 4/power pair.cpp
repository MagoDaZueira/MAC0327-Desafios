#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mod = 998244353;

ll expmod(ll x, ll ex, ll m) {
    if (ex == 0) return 1;

    ll half = expmod(x, ex / 2, m);
    half = (half * half) % m;

    if (ex % 2 == 0) return half;
    else return (half * x) % m;
}
 
void divisors(ll n, vector<ll>& divs) {
    ll sq = sqrt(n);
    for (int i = 1; i < sq; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n/i);
        }
    }
    if (n % sq == 0) {
        divs.push_back(sq);
        if (n / sq != sq) divs.push_back(n / sq);
    }
}

void prime_factors(ll n, unordered_map<ll, ll>& factors) {
    ll sq = sqrt(n);
    for (int i = 2; i <= sq; i++) {
        while (n % i == 0) {
            n /= i;
            factors[i]++;
        }
    }
    if (n > 1) factors[n]++;
}

ll totient(unordered_map<ll, ll>& factors) {
    ll res = 1;
    for (auto fact : factors) {
        res *= expmod(fact.first, fact.second-1, 1e13) * (fact.first - 1);
    }
    return res;
}
 
int main() {
    ll p; cin >> p;
    ll p1 = p - 1;

    vector<ll> divs;
    divisors(p1, divs);

    ll ans = 1;
    for (auto div : divs) {
        unordered_map<ll, ll> factors;
        prime_factors(div, factors);
        ll tot = totient(factors);
        ans = (ans + (((tot % mod) * (div % mod)) % mod)) % mod;
    }

    cout << ans;

    return 0;
}
