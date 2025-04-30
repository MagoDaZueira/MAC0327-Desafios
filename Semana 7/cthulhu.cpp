#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int last, vector<int> adj[], vector<bool>& visited, vector<int>& temp) {
    visited[node] = true;
    temp.push_back(node);

    for (int v : adj[node]) {
        if (!visited[v]) {
            if (dfs(v, node, adj, visited, temp)) {
                return true;
            }
        }
        else if (last != v) {
            temp.push_back(v);
            return true;
        }
    }

    temp.pop_back();
    return false;
}

void dfs_con(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;

    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs_con(v, adj, visited);
        }
    }
}

void create_set(set<int>& s, vector<int> origin) {
    int start = origin[origin.size()-1];
    s.insert(start);
    int i = origin.size() - 2;

    while (origin[i] != start) {
        s.insert(origin[i]);
        i--;
    }
}

int main() {
    int n, m; cin >> n >> m;

    vector<int> graph[n+1];
    vector<bool> visited(n+1, false);
    vector<bool> visit(n+1, false);
    vector<int> temp;

    int t1, t2;

    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }

    if (n == m) {

        dfs_con(1, graph, visit);

        bool conexo = true;
        for (int i = 1; i < n + 1; i++) {
            if (!visit[i]) {
                conexo = false;
            } 
        }

        if (conexo) {

            bool hasCycle = dfs(1, -1, graph, visited, temp);

            if (hasCycle) {
                cout << "FHTAGN!";
            }

            else {
                cout << "NO";
            }

        }

        else {
                cout << "NO";
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}