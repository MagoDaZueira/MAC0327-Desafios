#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void bfs(int y0, int x0, int n, int m, const vector<string>& grid, vector<vector<pair<int, int>>>& predecessor, vector<vector<char>>& step, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;

    q.push({y0, x0});
    visited[y0][x0] = true;

    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        int y = u.first;
        int x = u.second;

        if (y > 0) {
            if (!visited[y-1][x] && grid[y-1][x] != '#') {
                visited[y-1][x] = true;
                predecessor[y-1][x] = {y, x};
                step[y-1][x] = 'U';
                q.push({y-1, x});
            }
        }
        if (y < n-1) {
            if (!visited[y+1][x] && grid[y+1][x] != '#') {
                visited[y+1][x] = true;
                predecessor[y+1][x] = {y, x};
                step[y+1][x] = 'D';
                q.push({y+1, x});
            }
        }
        if (x > 0) {
            if (!visited[y][x-1] && grid[y][x-1] != '#') {
                visited[y][x-1] = true;
                predecessor[y][x-1] = {y, x};
                step[y][x-1] = 'L';
                q.push({y, x-1});
            }
        }
        if (x < m-1) {
            if (!visited[y][x+1] && grid[y][x+1] != '#') {
                visited[y][x+1] = true;
                predecessor[y][x+1] = {y, x};
                step[y][x+1] = 'R';
                q.push({y, x+1});
            }
        }
    }
}

void print_steps(int y, int x, const vector<string>& grid, vector<vector<pair<int, int>>>& predecessor, vector<vector<char>>& step) {
    stack<char> order;
    while (grid[y][x] != 'A') {
        order.push(step[y][x]);
        int old_y = y;
        int old_x = x;
        y = predecessor[old_y][old_x].first;
        x = predecessor[old_y][old_x].second;
    }

    cout << "YES" << endl;
    cout << order.size() << endl;
    while (!order.empty()) {
        cout << order.top();
        order.pop();
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> predecessor(n, vector<pair<int, int>>(m));
    vector<vector<char>> step(n, vector<char>(m));
    
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                bfs(i, j, n, m, grid, predecessor, step, visited);
                found = true;
            }
            if (found) break;
        }
        if (found) break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                if (visited[i][j]) {
                    print_steps(i, j, grid, predecessor, step);
                }
                else {
                    cout << "NO";
                }
                return 0;
            }
        }
    }

    return 0;
}
