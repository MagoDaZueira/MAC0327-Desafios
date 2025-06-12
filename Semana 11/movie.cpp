#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int, int> pii;

int main() {
    int n; cin >> n;
    vector<pii> v(n);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[i] = {b, a};
    }

    sort(v.begin(), v.end());

    int curr_b = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto [b, a] = v[i];
        if (a >= curr_b) {
            ans++;
            curr_b = b;
        }
    }

    cout << ans << endl;

    return 0;
}
