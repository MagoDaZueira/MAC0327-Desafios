#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;

const int MAXN = 1005;
const int LOG = ceil(log2(MAXN)) + 1;
vector<vector<int>> up(MAXN, vector<int>(LOG, -1));
vector<int> depth(MAXN, -1);

int n, m, k;

int get_depth(int v, vector<int>& parent) {
    if (depth[v] != -1) return depth[v];
    return depth[v] = get_depth(parent[v], parent) + 1;
}

void preprocess(vector<int>& parent) {
    depth[0] = 0;
    for (int i = 0; i <= m; i++) {
        up[i][0] = parent[i];
        get_depth(i, parent);
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= m; i++) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    vector<pii> control(n+1);
    vector<int> actual(n+1, 0);
    vector<int> parent(m+1);
    vector<tuple<ll,ll,ll>> fences(m+1);

    for (int i = 1; i <= n; i++) {
        cin >> control[i].first >> control[i].second;
    }

    for (int i = 0; i < m; i++) {
        ll r, x, y; cin >> r >> x >> y;
        fences[i] = {r, x, y};
    }
    fences[m] = {LLONG_MAX,0,0};

    sort(fences.begin(), fences.end(), [](const auto& a, const auto& b) {
        return get<0>(a) > get<0>(b);
    });

    for (int i = 1; i <= m; i++) {
        bool found = false;
        auto [r0, x0, y0] = fences[i];
        for (int j = i-1; j >= 1 && !found; j--) {
            auto [r, x, y] = fences[j];
            if ((x0-x)*(x0-x) + (y0-y)*(y0-y) < r*r) {
                parent[i] = j;
                found = true;
            }
        }
        if (!found) parent[i] = 0;

        for (int j = 1; j <= n; j++) {
            auto [x, y] = control[j];
            if ((x-x0)*(x-x0) + (y-y0)*(y-y0) < r0*r0) {
                actual[j] = i;
            }
        }
    }

    preprocess(parent);
    
    while (k--) {
        int a, b; cin >> a >> b;
        int u = actual[a];
        int v = actual[b];
        int common = lca(u, v);
        int dist = (depth[u] - depth[common]) + (depth[v] - depth[common]);
        cout << dist << endl;
    }
}
