#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAXN = 200005;
const int LOG = ceil(log2(MAXN)) + 1;
vector<vector<int>> up(MAXN, vector<int>(LOG, -1));
vector<int> depth(MAXN, -1);

int n, m;

void dfs(int x, int parent, vector<vector<int>>& adj) {
    for (auto v : adj[x]) {
        if (v != parent) {
            depth[v] = depth[x] + 1;
            up[v][0] = x;
            dfs(v, x, adj);
        }
    }
}

void preprocess(vector<vector<int>>& adj) {
    depth[1] = 0;
    dfs(1, -1, adj);

    for (int j = 1; j < LOG; j++) {
        for (int i = 2; i <= n; i++) {
            if (up[i][j-1] != -1) 
                up[i][j] = up[up[i][j-1]][j-1];
            else
                up[i][j] = -1;
        }
    }
}

int kth_ancestor(int x, int k) {
    if (depth[x] < k) return -1;

    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            x = up[x][j];
        }
    }

    return x;
}

int lca(int a, int b) {
    int diff = depth[a] - depth[b];
    if (diff < 0)      b = kth_ancestor(b, -diff);
    else if (diff > 0) a = kth_ancestor(a, diff);

    if (a == b) return a;

    for (int i = LOG-1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int paths(int x, int parent, vector<vector<int>>& adj, vector<int>& end_count, vector<int>& lca_count, vector<int>& ans) {
    int res = end_count[x];
    for (auto v : adj[x]) {
        if (v != parent) {
            res += paths(v, x, adj, end_count, lca_count, ans);
        }
    }
    ans[x] = res - lca_count[x];
    return res - 2 * lca_count[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for (int i = 2; i <= n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    preprocess(adj);

    vector<int> end_count(n+1, 0);
    vector<int> lca_count(n+1, 0);
    
    while (m--) {
        int a, b; cin >> a >> b;
        int common = lca(a, b);
        lca_count[common]++;
        end_count[a]++;
        end_count[b]++;
    }
    
    vector<int> ans(n+1);
    paths(1, -1, adj, end_count, lca_count, ans);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
