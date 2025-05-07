#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

struct Edge {
    ll x;
    ll y;
};

int main() {
    ll n, m, t; cin >> n >> m >> t;
    vector<vector<pair<int, Edge>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        Edge r;
        int a, b; cin >> a >> b >> r.x >> r.y;
        adj[a].push_back({b, r});
        adj[b].push_back({a, r});
    }

    vector<ll> dist(n+1, LLONG_MAX);
    dist[1] = t;
    priority_queue<pli, vector<pli>, greater<pli>> fila_dijkstra;
    fila_dijkstra.push({dist[1],1});

    while(!fila_dijkstra.empty()){
        auto [d, next] = fila_dijkstra.top();
        fila_dijkstra.pop();
        if (dist[next] < d) continue;
        for (auto [v, r] : adj[next]){
            ll time_cycle = d % (r.x + r.y);
            if (time_cycle < r.x) {
                if (dist[v] <= d) continue;
                dist[v] = dist[next];
            }
            else {
                int wait = (r.x + r.y) - time_cycle;
                if (dist[v] <= d + wait) continue;
                dist[v] = dist[next] + wait;
            }
            fila_dijkstra.push({dist[v], v});
        }
    }

    cout << dist[n];

    return 0;
}
