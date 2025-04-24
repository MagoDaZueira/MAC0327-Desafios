#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
// ====================== Solução 1 ======================
int main() {
    int n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < n-1; i++) {
        int goal1 = v[i] + k;
        auto it1 = lower_bound(v.begin() + i + 1, v.end(), goal1);
        auto it2 = upper_bound(v.begin() + i + 1, v.end(), goal1);
        ans += distance(it1, it2);
    }
    
    cout << ans;

    return 0;
}

// ====================== Solução 2 ======================
// int main() {
//     int n, k; cin >> n >> k;
//     vector<ll> v(n);
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//     }

//     unordered_map<int, int> counter;
//     for (int i = 0; i < n; i++) {
//         counter[v[i]]++;
//     }

//     ll ans = 0;
//     for (int i = 0; i < n; i++) {
//         ans += counter[v[i] + k];
//     }

//     cout << ans;

//     return 0;
// }
