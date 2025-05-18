#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;

const int MAXN = 100005;
const int LOG = ceil(log2(MAXN)) + 1;
vector<vector<int>> up(MAXN, vector<int>(LOG, -1));
vector<int> depth(MAXN, -1);
vector<int> pre(MAXN, -1);
vector<int> pos(MAXN, -1);
vector<vector<int>> children(MAXN);

int n, m;

int current_time = 0;
void dfs(int u, int current_depth) {
    pre[u] = current_time++;
    depth[u] = current_depth;
    for (auto v : children[u]) {
        dfs(v, current_depth + 1);
    }
    pos[u] = current_time;
}

void preprocess(vector<int>& parent) {
    for (int i = 1; i <= n; i++) {
        up[i][0] = parent[i];
        if (parent[i] == 0) {
            up[i][0] = -1;
            dfs(i, 0);
        }
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
        if (parent[i] != 0)
            children[parent[i]].push_back(i);
    }

    cin >> m;

    preprocess(parent);

    vector<vector<int>> depth_pre(n+1);

    for (int i = 1; i <= n; i++) {
        depth_pre[depth[i]].push_back(pre[i]);
    }

    for (auto& vec : depth_pre) {
        sort(vec.begin(), vec.end());
    }
    
    while (m--) {
        int v, p; cin >> v >> p;
        int pth = kth_ancestor(v, p);

        if (pth == -1) {
            cout << 0 << " ";
            continue;
        }

        auto lo = lower_bound(depth_pre[depth[v]].begin(), depth_pre[depth[v]].end(), pre[pth]);
        auto hi = lower_bound(depth_pre[depth[v]].begin(), depth_pre[depth[v]].end(), pos[pth]);
        int dist = distance(lo, hi);
        int ans = dist ? dist - 1 : 0;
        cout << ans << " ";
    }
}
