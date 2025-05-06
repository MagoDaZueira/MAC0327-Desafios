#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> dist(n+1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> fila_dijkstra;
    fila_dijkstra.push({dist[1],1});

    while(!fila_dijkstra.empty()){
        auto [d, next] = fila_dijkstra.top();
        fila_dijkstra.pop();
        if (dist[next] < d) continue;
        for (auto [v, w] : adj[next]){
            if (dist[v] <= d+w) continue;
            dist[v] = dist[next] + w;
            fila_dijkstra.push({dist[v], v});
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
