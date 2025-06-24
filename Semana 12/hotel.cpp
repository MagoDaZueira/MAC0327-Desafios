#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 200005;
vector<int> arr(MAXN);
vector<ll> seg(4 * MAXN);

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int update(int node, int l, int r, int val) {
    if (l == r) {
        seg[node] -= val;
        return l;
    }
    int mid = (l + r) / 2;
    int ret;
    if (seg[2 * node] >= val) ret = update(2 * node, l, mid, val);
    else                      ret = update(2 * node + 1, mid + 1, r, val);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    return ret;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n-1);

    while (m--) {
        int r; cin >> r;
        if (r > seg[1]) cout << 0 << " ";
        else cout << update(1, 0, n-1, r) + 1 << " ";
    }

    return 0;
}
