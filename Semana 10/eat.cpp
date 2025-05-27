#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 505;
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

ll expmod(ll x, ll ex, ll m) {
    if (ex == 0) return 1;

    ll half = expmod(x, ex / 2, m);
    half = (half * half) % m;

    if (ex % 2 == 0) return half;
    else return (half * x) % m;
}

int main() {
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int w = (expmod(a[i], a[j], m) + expmod(a[j], a[i], m)) % m;
                edges.push_back({w, i, j});
            }
        }
    }

    for (int i = 0; i < n; i++) parent[i] = i;

    sort(edges.begin(), edges.end());
    
    ll ans = 0;
    for (int i = edges.size()-1; i >= 0; i--) {
        int a = get<1>(edges[i]);
        int b = get<2>(edges[i]);
        if (find(a) == find(b)) continue;
        ans += get<0>(edges[i]);
        unite(a, b);
    }

    cout << ans << endl;

    return 0;
}
