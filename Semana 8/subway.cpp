#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int b, e; cin >> b >> e;

    set<pii> visited;
    deque<tuple<int, int, int>> dq;
    dq.push_front({b, -1, 0});

    while (!dq.empty()) {
        auto [curr, last_color, d] = dq.front();
        dq.pop_front();

        if (curr == e) {
            cout << d << endl;
            return;
        }

        for (auto [v, c] : adj[curr]) {
            if (visited.count({v, c})) continue;
            visited.insert({v, c});

            if (c == last_color) {
                dq.push_front({v, c, d});
            } else {
                dq.push_back({v, c, d + 1});
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
