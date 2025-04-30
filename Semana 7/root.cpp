#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dfs(int u, vector<vector<int>>& adj, vector<ll>& a, vector<bool>& visited) {
    visited[u] = true;
    if (adj[u].size() == 0) return a[u];

    ll small = LLONG_MAX;
    for (int v : adj[u]) {
        if (!visited[v]) {
            small = min(small, dfs(v, adj, a, visited));
        }
    }

    ll res;
    if (u == 1) res = a[u] + small;
    else if (small < a[u]) res = small;
    else                   res = (a[u] + small) / 2;

    return res;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n+1);
    vector<vector<int>> adj(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }

    vector<bool> visited(n+1, false);

    ll ans = dfs(1, adj, a, visited);
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
