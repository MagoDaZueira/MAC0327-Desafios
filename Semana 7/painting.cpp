#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n;
int root;

ll dfs_size(int u, int parent, vector<vector<int>>& adj, vector<int>& count, vector<int>& parents, vector<int>& leaves) {
    if (adj[u].size() == 1) leaves.push_back(u);
    int res = 1;
    for (auto v : adj[u]) {
        if (v != parent) {
            parents[v] = u;
            res += dfs_size(v, u, adj, count, parents, leaves);
        }
    }
    return count[u] = res;
}

ll dfs_down(int u, int parent, vector<vector<int>>& adj, vector<ll>& dp, vector<int>& count) {
    ll res = count[u];
    for (auto v : adj[u]) {
        if (v != parent) {
            res += dfs_down(v, u, adj, dp, count);
        }
    }
    return dp[u] = res;
}

ll dfs_up(int u, int prev, vector<vector<int>>& adj, vector<int>& parents, vector<int>& count, vector<ll>& dp_up, vector<ll>& dp_down) {
    if (u == parents[root]) return 0;

    ll res;
    if (prev == -2) res = n;
    else {
        res = dp_down[u] - dp_down[prev] - count[prev];
        res += n - count[u];
    }

    if (dp_up[u] != -1) return dp_up[u] + res;

    dp_up[u] = dfs_up(parents[u], u, adj, parents, count, dp_up, dp_down);
    return dp_up[u] + res;
}

int main() {
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (n == 2) {
        cout << 3 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 1) {
            root = i;
            break;
        }
    }

    vector<int> parents(n+1);
    vector<int> count(n+1);
    vector<int> leaves;

    vector<ll> dp_down(n+1, -1);
    vector<ll> dp_up(n+1, -1);

    parents[root] = -1;
    dfs_size(root, -1, adj, count, parents, leaves);

    dp_down[root] = dfs_down(root, -1, adj, dp_down, count);
    dp_up[root] = 0;

    ll ans = 0;
    for (auto leaf : leaves) {
        ll temp = dfs_up(leaf, -2, adj, parents, count, dp_up, dp_down);
        ans = max(ans, temp);
    }

    cout << ans;

    return 0;
}
