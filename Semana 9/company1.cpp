#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAXN = 200005;
const int LOG = ceil(log2(MAXN)) + 1;
vector<vector<int>> up(MAXN, vector<int>(LOG, -1));
vector<int> depth(MAXN, -1);

int n, q;

int get_depth(int v, vector<int>& parent) {
    if (depth[v] != -1) return depth[v];
    return depth[v] = get_depth(parent[v], parent) + 1;
}

void preprocess(vector<int>& parent) {
    depth[1] = 0;
    for (int i = 2; i <= n; i++) {
        up[i][0] = parent[i];
        get_depth(i, parent);
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 2; i <= n; i++) {
            if (up[i][j-1] != -1) 
                up[i][j] = up[up[i][j-1]][j-1];
            else
                up[i][j] = -1;
        }
    }
}

int get_kth(int x, int k) {
    if (depth[x] < k) return -1;

    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            x = up[x][j];
        }
    }

    return x;
}

int main() {
    cin >> n >> q;
    vector<int> parent(n+1);

    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }

    preprocess(parent);
    
    while (q--) {
        int x, k; cin >> x >> k;
        cout << get_kth(x, k) << endl;
    }
}
