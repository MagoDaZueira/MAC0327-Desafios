#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 3005;
vector<int> parent(MAXN);
vector<int> depth(MAXN, 0);

vector<vector<pair<int, int>>> adj(MAXN);
vector<bool> visited(MAXN, false);

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);

    if (root_a == root_b) return;

    if (depth[root_a] < depth[root_b]) {
        parent[root_a] = root_b;
    }
    else if (depth[root_a] > depth[root_b]) {
        parent[root_b] = root_a;
    }
    else {
        parent[root_b] = root_a;
        depth[root_a]++;
    }
}

void dfs(int u, int start, int curr_max, vector<vector<pair<int, int>>>& adj, vector<vector<ll>>& dist) {
    visited[u] = true;
    dist[start][u] = curr_max;
    for (auto [v, w] : adj[u]) {
        if (visited[v]) continue;
        dfs(v, start, max(w, curr_max), adj, dist);
    }
    visited[u] = false;
}

void solve(int test) {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int> > edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }

    vector<vector<ll>> dist(n+1, vector<ll>(n+1));
    vector<vector<pair<int, int>>> adj(n+1);

    for (int i = 1; i <= n; i++) parent[i] = i;

    sort(edges.begin(), edges.end());
    
    for (int i = 0; i < m; i++) {
        int a = get<1>(edges[i]);
        int b = get<2>(edges[i]);
        if (find(a) == find(b)) continue;

        int c = get<0>(edges[i]);
        unite(a, b);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, i, 0, adj, dist);
    }

    int q; cin >> q;
    cout << "Case " << test << endl;
    while (q--) {
        int k, t; cin >> k >> t;
        cout << dist[k][t] << endl;
    }
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
        cout << endl;
    }
    return 0;
}
