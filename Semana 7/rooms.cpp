#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<char> >& layout, vector<vector<bool> >& visited) {
    int n = layout.size();
    int m = layout[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || layout[x][y] == '#' || visited[x][y]) {
        return;
    }
    visited[x][y] = true;
    dfs(x + 1, y, layout, visited);
    dfs(x - 1, y, layout, visited);
    dfs(x, y + 1, layout, visited);
    dfs(x, y - 1, layout, visited);
}

int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<char> > layout(n, vector<char>(m));
    vector<vector<bool> > visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> layout[i][j];
        }
    }

    int roomCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (layout[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, layout, visited);
                roomCount++;
            }
        }
    }

    cout << roomCount << endl;
    return 0;
}
