#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<ll, int>> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i+1;
    }
    int k; cin >> k;

    sort(x.begin(), x.end());

    ll sum = 0;
    ll pref = 0;
    ll pref_back = 0;
    for (int i = 1; i < k; i++) {
        sum += (x[i].first - x[i-1].first) * i + pref;
        pref += (x[i].first - x[i-1].first) * i;
        pref_back += x[i].first - x[0].first;
    }

    ll best = sum;
    int best_i = 0;

    int k1 = k - 1;
    int i = 1;
    int j = k;
    while (j < n) {
        sum -= pref_back;
        pref_back -= (x[i].first - x[i-1].first) * k1;

        pref_back += x[j].first - x[i].first;
        pref -= x[j-1].first - x[i-1].first;
        
        sum += (x[j].first - x[j-1].first) * k1 + pref;
        pref += (x[j].first - x[j-1].first) * k1;

        if (sum < best) {
            best = sum;
            best_i = i;
        }

        i++;
        j++;
    }

    for (int t = best_i; t < best_i + k; t++) {
        cout << x[t].second << " ";
    }
}
