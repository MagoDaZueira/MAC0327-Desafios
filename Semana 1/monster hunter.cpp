#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll dp(int v, int round, vector<vector<int> >& edges, vector<ll>& a, vector<vector<ll> >& memo, int dad) {

    if (memo[v][round] != -1)
        return memo[v][round];
    
    ll res = 0;
    int max_rounds = memo[0].size();

    for (auto& vert : edges[v]) {
        if (vert != dad) {
            ll temp = LLONG_MAX;
            for (int r = 0; r < max_rounds; r++) {
                if (r != round) {
                    temp = min(temp, dp(vert, r, edges, a, memo, v));
                }
            }
            res += temp;
        }
    }

    res += a[v] * (round+1);

    return memo[v][round] = res;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<ll> a(n+1);
        vector<vector<int> > edges(n+1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        if      (n == 1) cout << a[1] << endl;
        else if (n == 2) cout << max(a[1], a[2]) + 2 * min(a[1], a[2]) << endl;

        else {
            int root = 0;
            for (int i = 1; i <= n; i++) {
                if (edges[i].size() > 1) {
                    root = i;
                    break;
                }
            }

            int max_steps = log2(n);
            vector<vector<ll> > memo(n+1, vector<ll>(max_steps+1, -1));

            ll ans = LLONG_MAX;
            for (int i = 0; i <= max_steps; i++) {
                ans = min(ans, dp(root, i, edges, a, memo, 0));
            }

            cout << ans << endl;
        }
    }

    return 0;
}