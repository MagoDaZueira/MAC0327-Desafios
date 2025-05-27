#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 100005;
vector<int> parent(MAXN);
vector<int> depth(MAXN, 0);

vector<int> comp_size(MAXN, 1);
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
        comp_size[root_b] += comp_size[root_a];
    }
    else if (depth[root_a] > depth[root_b]) {
        parent[root_b] = root_a;
        comp_size[root_a] += comp_size[root_b];
    }
    else {
        parent[root_b] = root_a;
        comp_size[root_a] += comp_size[root_b];
        depth[root_a]++;
    }
}

int find_size(int a) {
    return comp_size[find(a)];
}

// int find_size(int a) {
//     if (parent[a] == a) return comp_size[a];
//     return find_size(parent[a]);
// }

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;

    components = n;
    int largest = 1;

    while (m--) {
        int a, b; cin >> a >> b;
        unite(a, b);
        int this_size = find_size(a);
        largest = max(largest, this_size);
        cout << components << " " << largest << endl;
    }

    return 0;
}