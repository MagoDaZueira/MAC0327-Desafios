#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
void divisors(ll n, vector<ll>& divs, unordered_set<ll>& in_a) {
    ll sq = sqrt(n);
    if(!in_a.count(1)) divs.push_back(1);
    
    for (int i = 2; i < sq; i++) {
        if (n % i == 0) {
            if (!in_a.count(i))   divs.push_back(i);
            if (!in_a.count(n/i)) divs.push_back(n/i);
        }
    }
    if (n % sq == 0) {
        if (!in_a.count(sq))                   divs.push_back(sq);
        if (n / sq != sq && !in_a.count(n/sq)) divs.push_back(n / sq);
    }
}
 

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    unordered_set<ll> in_a;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        in_a.insert(a[i]);
    }
    
    ll big = 0;
    ll lcm_max = 1;
    for (int i = 0; i < n; i++) {
        big = max(big, a[i]);
        lcm_max = lcm(lcm_max, a[i]);
        if (lcm_max > 1e9) {
            cout << n << endl;
            return; 
        }
    }
 
    if (lcm_max > big) {
        cout << n << endl;
        return; 
    }
 
    vector<ll> divs;
    divisors(big, divs, in_a);
 
    int ans = 0;
    for (auto div : divs) {
        ll current_lcm = 1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (div % a[i] == 0) {
                current_lcm = lcm(current_lcm, a[i]);
                count++;
            }
        }
        if (current_lcm == div) {
            ans = max(ans, count);
        }
    }
 
    cout << ans << endl;
    return;
}
 
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}