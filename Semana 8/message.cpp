#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void bfs(const vector<vector<int>>& adj, vector<int>& predecessor, vector<bool>& visited) {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                predecessor[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    vector<int> predecessor(n+1, -1);
    
    bfs(adj, predecessor, visited);

    if (!visited[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    stack<int> order;
    for (int curr = n; curr != -1; curr = predecessor[curr]) {
        order.push(curr);
    }

    cout << order.size() << endl;
    while (!order.empty()) {
        cout << order.top() << " ";
        order.pop();
    }

    return 0;
}
