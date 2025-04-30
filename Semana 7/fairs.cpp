#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(int u, int stop, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v] && v != stop) {
            dfs(v, stop, adj, visited);
        }
    }
}

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> found_a(n+1, false);
    dfs(a, b, adj, found_a);

    vector<bool> found_b(n+1, false);
    dfs(b, a, adj, found_b);

    ll exclusive_a = -1; ll exclusive_b = -1;
    for (int i = 1; i <= n; i++) {
        if      (found_a[i] && !found_b[i]) exclusive_a++;
        else if (!found_a[i] && found_b[i]) exclusive_b++;
    }

    cout << exclusive_a * exclusive_b << endl;
    
    return;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
