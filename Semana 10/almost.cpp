#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 100005;
vector<int> parent(2 * MAXN);
vector<int> depth(MAXN, 0);

vector<int> actual(MAXN);
vector<int> amount(MAXN);
vector<ll> sum(MAXN);

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    int root_a = find(actual[a]);
    int root_b = find(actual[b]);

    if (root_a == root_b) return;

    if (depth[root_a] < depth[root_b]) {
        parent[root_a] = root_b;
        amount[root_b] += amount[root_a];
        sum[root_b] += sum[root_a];
    }
    else if (depth[root_a] > depth[root_b]) {
        parent[root_b] = root_a;
        amount[root_a] += amount[root_b];
        sum[root_a] += sum[root_b];
    }
    else {
        parent[root_b] = root_a;
        depth[root_a]++;
        amount[root_a] += amount[root_b];
        sum[root_a] += sum[root_b];
    }
}

int current_actual;
void transfer(int a, int b) {
    int root_a = find(actual[a]);
    int root_b = find(actual[b]);
    if (root_a == root_b) return;

    int new_actual = current_actual++;

    amount[root_a]--;
    amount[root_b]++;
    sum[root_a] -= a;
    sum[root_b] += a;
    parent[new_actual] = root_b;
    actual[a] = new_actual;
}

void solve(int n, int m) {
    for (int i = 1; i <= n; i++) {
        depth[i] = 0;
        parent[i] = i;
        amount[i] = 1;
        sum[i] = i;
        actual[i] = i;
    }
    current_actual = n + 1;

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
            int root = find(actual[p]);
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
