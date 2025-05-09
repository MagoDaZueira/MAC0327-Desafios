#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<vector<int>>> out(26, vector<vector<int>>(n+1));
    vector<vector<vector<int>>> in(26, vector<vector<int>>(n+1));
    for (int i = 0; i < m; i++) {
        int a, b; char c; cin >> a >> b >> c;
        out[c-'a'][a].push_back(b);
        in[c-'a'][b].push_back(a);
    }

    vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
    queue<pii> q;
    set<pii> start_ans;

    for (int u = 1; u <= n; u++) {
        visited[u][u] = true;
        q.push({u, u});
        for (int c = 0; c < 26; c++) {
            for (auto v : out[c][u]) {
                if (visited[v][u]) continue;
                visited[v][u] = true;
                q.push({v, u});
                start_ans.insert({u, v});
            }
        }
    }

    int ans = start_ans.size();

    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();

        for (int c = 0; c < 26; c++) {
            for (auto u2 : out[c][u]) {
                for (auto v2 : in[c][v]) {
                    if (visited[u2][v2]) continue;
                    visited[u2][v2] = true;
                    q.push({u2, v2});
                    ans++;
                }
            }
        }
    }

    cout << ans;
}
