#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 100005;
vector<int> parent(MAXN);
vector<int> depth(MAXN, 0);

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

int main() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int> > edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }

    for (int i = 1; i <= n; i++) parent[i] = i;

    sort(edges.begin(), edges.end());
    
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int a = get<1>(edges[i]);
        int b = get<2>(edges[i]);
        if (find(a) == find(b)) continue;
        ans += get<0>(edges[i]);
        unite(a, b);
    }

    int component = find(1);
    for (int i = 2; i <= n; i++) {
        if (find(i) != component) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}