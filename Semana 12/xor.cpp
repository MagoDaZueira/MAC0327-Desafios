#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 200005;
vector<int> arr(MAXN);
vector<ll> seg(4 * MAXN);

void build(int node, int l, int r, bool is_or) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid, !is_or);
    build(2 * node + 1, mid + 1, r, !is_or);
    if (is_or) seg[node] = seg[2 * node] | seg[2 * node + 1];
    else       seg[node] = seg[2 * node] ^ seg[2 * node + 1];
}

ll update(int node, int l, int r, int idx, int val, bool is_or) {
    if (l == r) {
        seg[node] = val;
        return seg[node];
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(2 * node, l, mid, idx, val, !is_or);
    else            update(2 * node + 1, mid + 1, r, idx, val, !is_or);
    if (is_or) seg[node] = seg[2 * node] | seg[2 * node + 1];
    else       seg[node] = seg[2 * node] ^ seg[2 * node + 1];
    return seg[node];
}

int main() {
    int n, m; cin >> n >> m;
    int n2 = 1 << n;
    for (int i = 0; i < n2; i++) {
        cin >> arr[i];
    }

    build(1, 0, n2-1, n % 2);

    while (m--) {
        int p, b; cin >> p >> b;
        cout << update(1, 0, n2-1, p-1, b, n % 2) << endl;
    }

    return 0;
}
