#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool dfs(int u, bool team, vector<bool>& teams, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    teams[u] = team;

    bool possible = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            possible = possible && dfs(v, !team, teams, adj, visited);
        }
        else if (teams[u] == teams[v]) {
            return false;
        }
    }

    return possible;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1);
    vector<bool> teams(n+1);
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool possible = dfs(i, 0, teams, adj, visited);
            if (!possible) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << teams[i] + 1 << " ";
    }

    return 0;
}
