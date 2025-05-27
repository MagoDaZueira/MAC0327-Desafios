#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 100005;
vector<int> parent(MAXN);
vector<int> depth(MAXN, 0);

int components;

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);

    if (root_a == root_b) return;

    components--;

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
    vector<pair<int,int>> edges(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    int q; cin >> q;
    vector<int> removed(q);
    vector<bool> intact(m+1, true);
    for (int i = q-1; i >= 0; i--) {
        cin >> removed[i];
        intact[removed[i]] = false;
    }

    components = n;
    
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= m; i++) {
        if (intact[i])
        unite(edges[i].first, edges[i].second);
    }
    
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        ans[i] = components;
        auto [a, b] = edges[removed[i]];
        unite(a, b);
    }

    for (int i = q-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}
