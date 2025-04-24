#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int large_interval(int i, string& s, int k, vector<int>& pref_a, vector<int>& pref_b, bool use_a) {
    int lo = i + 1;
    int hi = pref_a.size() - 1;
    int mid, dist, start_pref;

    if (use_a) start_pref = - pref_a[i] + (s[i] == 'a');
    else       start_pref = - pref_b[i] + (s[i] == 'b');

    int ans = i;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

        if (use_a) dist = pref_a[mid] + start_pref;
        else       dist = pref_b[mid] + start_pref;

        if (dist <= k) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> pref_a(n);
    vector<int> pref_b(n);
    pref_a[0] = s[0] == 'a';
    pref_b[0] = s[0] == 'b';
    for (int i = 1; i < n; i++) {
        pref_a[i] = pref_a[i-1] + (s[i] == 'a');
        pref_b[i] = pref_b[i-1] + (s[i] == 'b');
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int azul   = large_interval(i, s, k, pref_a, pref_b, false);
        int branco = large_interval(i, s, k, pref_a, pref_b, true);
        ans = max(ans, max(azul, branco) - i + 1);
    }

    cout << ans;

    return 0;
}
