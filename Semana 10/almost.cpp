#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 100005;
vector<int> parent(MAXN);
vector<int> depth(MAXN, 0);

vector<set<int>> children(MAXN);
vector<int> amount(MAXN);
vector<ll> sum(MAXN);

int find(int a) {
    if (parent[a] == a) return a;
    int root = find(parent[a]);
    // if (parent[a] != root) {
        children[parent[a]].erase(a);
        children[root].insert(a);
    // }
    return parent[a] = root;
}
// int find(int a) {
//     if (parent[a] == a) return a;
//     return find(parent[a]);
//     // return parent[a] = find(parent[a]);
// }

void unite(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);

    if (root_a == root_b) return;

    if (depth[root_a] < depth[root_b]) {
        parent[root_a] = root_b;
        amount[root_b] += amount[root_a];
        sum[root_b] += sum[root_a];
        children[root_b].insert(root_a);
    }
    else if (depth[root_a] > depth[root_b]) {
        parent[root_b] = root_a;
        amount[root_a] += amount[root_b];
        sum[root_a] += sum[root_b];
        children[root_a].insert(root_b);
    }
    else {
        parent[root_b] = root_a;
        depth[root_a]++;
        amount[root_a] += amount[root_b];
        sum[root_a] += sum[root_b];
        children[root_a].insert(root_b);
    }
}

void transfer(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a == root_b) return;

    if (root_a == a && !children[a].empty()) {
        root_a = *children[a].begin();
        amount[root_a] = amount[a];
        sum[root_a] = sum[a];
        parent[root_a] = root_a;
    }
    for (auto child : children[a]) {
        if (child != root_a) {
            children[root_a].insert(child);
            parent[child] = root_a;
        }
    }
    children[a].clear();
    children[root_b].insert(a);

    amount[root_a]--;
    amount[root_b]++;
    sum[root_a] -= a;
    sum[root_b] += a;
    children[parent[a]].erase(a);
    parent[a] = root_b;
}

void solve(int n, int m) {
    for (int i = 1; i <= n; i++) {
        depth[i] = 0;
        parent[i] = i;
        amount[i] = 1;
        sum[i] = i;
        children[i].clear();
    }

    while (m--) {
        int op; cin >> op;
        int p, q; op == 3 ? cin >> p : cin >> p >> q;

        if (op == 1) {
            unite(p, q);
        }
        else if (op == 2) {
            transfer(p, q);
        }
        else {
            int root = find(p);
            cout << amount[root] << " " << sum[root] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
}
