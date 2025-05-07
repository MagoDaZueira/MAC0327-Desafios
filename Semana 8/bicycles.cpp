#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,pair<int, int>> ppii;

const int S_MAX = 1001;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<int> s(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    vector<vector<ll>> dist(n+1, vector<ll>(S_MAX, LLONG_MAX));
    dist[1][s[1]] = 0;
    priority_queue<ppii, vector<ppii>, greater<ppii>> fila_dijkstra;
    fila_dijkstra.push({dist[1][s[1]], {1, s[1]}});

    while(!fila_dijkstra.empty()){
        auto [d, inner] = fila_dijkstra.top();
        auto [next, si] = inner;
        fila_dijkstra.pop();
        
        if (dist[next][si] < d) continue;
        for (auto [v, w] : adj[next]){
            ll curr_s = min(s[next], si);
            ll total = curr_s * w;

            if (dist[v][curr_s] <= d + total) continue;

            dist[v][curr_s] = dist[next][si] + total;
            fila_dijkstra.push({dist[v][curr_s], {v, curr_s}});
        }
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < S_MAX; i++) {
        ans = min(ans, dist[n][i]);
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
