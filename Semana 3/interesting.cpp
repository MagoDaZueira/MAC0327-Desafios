#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int q; cin >> q;
    vector<int> money(q);
    for (int i = 0; i < q; i++) {
        cin >> money[i];
    }

    sort(prices.begin(), prices.end());

    for (int i = 0; i < q; i++) {
        auto it = upper_bound(prices.begin(), prices.end(), money[i]);
        int ans = it - prices.begin();
        cout << ans << endl;
    }

    return 0;
}
