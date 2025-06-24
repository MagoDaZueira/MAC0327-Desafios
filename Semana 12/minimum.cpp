#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 200005;
vector<int> arr(MAXN);
vector<ll> seg(4 * MAXN, LLONG_MAX);

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

ll query(int node, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return LLONG_MAX;
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return min(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(2 * node, l, mid, idx, val);
    else            update(2 * node + 1, mid + 1, r, idx, val);
    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

int main() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n-1);

    while (q--) {
        int mode, a, b; cin >> mode >> a >> b;
        if (mode == 1) update(1, 0, n-1, a-1, b);
        else           cout << query(1, 0, n-1, a-1, b-1) << endl;
    }

    return 0;
}
