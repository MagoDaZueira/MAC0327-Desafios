#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back(c);
        adj[b].push_back(c);
    }
    int b, e; cin >> b >> e;

    int v_count = n+1;
    unordered_map<int, int> c_to_v;
    for (int i = 1; i <= n; i++) {
        for (auto c : adj[i]) {
            if (!c_to_v.count(c)) {
                c_to_v[c] = v_count++;
            }
        }
    }

    vector<vector<int>> adj2(v_count+1);
    for (int i = 1; i <= n; i++) {
        for (auto c : adj[i]) {
            int color = c_to_v[c];
            adj2[i].push_back(color);
            adj2[color].push_back(i);
        }
    }

    vector<bool> visited(v_count+1, false);
    queue<pii> q;
    q.push({b, 0});

    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();

        if (u == e) {
            cout << d/2 << endl;
            return;
        }

        for (auto v : adj2[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push({v, d + 1});
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
