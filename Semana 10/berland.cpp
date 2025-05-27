#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 1005;
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
    int n; cin >> n;
    vector<pair<int, int>> edges(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    for (int i = 1; i <= n; i++) parent[i] = i;
    
    vector<bool> useful(n-1, false);
    for (int i = 0; i < n-1; i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        if (find(a) == find(b)) continue;
        unite(a, b);
        useful[i] = true;
    }

    set<int> chosen;
    for (int i = 1; i <= n; i++) {
        int component = find(i);
        chosen.insert(component);
    }

    vector<int> useless;
    for (int i = 0; i < n-1; i++) {
        if (!useful[i]) useless.push_back(i);
    }

    int t = chosen.size() - 1;
    cout << t << endl;

    int start = *chosen.begin();
    chosen.erase(start);
    int useless_idx = 0;

    for (auto component : chosen) {
        auto [a, b] = edges[useless[useless_idx++]];
        cout << a << " " << b << " " << start << " " << component << endl;
    }

    return 0;
}
