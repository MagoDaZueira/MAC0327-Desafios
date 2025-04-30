#include <bits/stdc++.h>
#define ll long long int
using namespace std;

char current_char;
int vertex_count;
int edge_count;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<char>& s) {
    visited[u] = true;
    vertex_count++;
    s[u] = current_char;

    for (int v : adj[u]) {
        if (s[v] != 'b') edge_count++;
        if (!visited[v]) {
            dfs(v, adj, visited, s);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unsigned int b_size = n - 1;
    vector<bool> is_b(n+1, false);
    vector<char> s(n+1, 'd');
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == b_size) {
            visited[i] = true;
            s[i] = 'b';
        }
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            if (components > 2) {
                cout << "No" << endl;
                return 0;
            }

            if (components == 1) current_char = 'a';
            else                 current_char = 'c';

            vertex_count = 0;
            edge_count = 0;
            dfs(i, adj, visited, s);

            if (edge_count != vertex_count * (vertex_count - 1)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
}
