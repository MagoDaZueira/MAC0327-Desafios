#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;

pii dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char step_vec[4] = {'U', 'D', 'L', 'R'};

int n, m;

bool is_valid_mon(int y, int x, vector<string>& grid, vector<vector<bool>>& visited) {
    return (y >= 0 && y < n && x >= 0 && x < m && !visited[y][x] && grid[y][x] != '#');
}
bool is_valid_human(int y, int x, vector<string>& grid, vector<vector<bool>>& visited, int dist, vector<vector<int>>& monster_dist) {
    return (y >= 0 && y < n && x >= 0 && x < m && !visited[y][x] && grid[y][x] != '#' && (dist < monster_dist[y][x] || monster_dist[y][x] == -1));
}

void print_steps(int y, int x, vector<string>& grid, vector<vector<pair<int, int>>>& predecessor, vector<vector<char>>& step) {
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
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> monster_dist(n, vector<int>(m, -1));
    queue<pii> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monster_dist[i][j] = 0;
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int next_y = y + dir[i].first;
            int next_x = x + dir[i].second;
            if (is_valid_mon(next_y, next_x, grid, visited)) {
                visited[next_y][next_x] = true;
                monster_dist[next_y][next_x] = monster_dist[y][x] + 1;
                q.push({next_y, next_x});
            }
        }
    }


    int y0, x0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                y0 = i;
                x0 = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (y0 == 0 || y0 == n-1 || x0 == 0 || x0 == m-1) {
        cout << "YES" << endl << 0;
        return 0;
    }

    for (auto& row : visited) {
        fill(row.begin(), row.end(), false);
    }

    vector<vector<pii>> predecessor(n+1, vector<pii>(m, {-1, -1}));
    vector<vector<int>> human_dist(n, vector<int>(m, -1));
    vector<vector<char>> steps(n, vector<char>(m));

    human_dist[y0][x0] = 0;
    visited[y0][x0] = true;
    q.push({y0, x0});

    int end_y = -1;
    int end_x = -1;
    found = false;

    while (!q.empty() && !found) {
        auto [y, x] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int next_y = y + dir[i].first;
            int next_x = x + dir[i].second;
            if (is_valid_human(next_y, next_x, grid, visited, human_dist[y][x]+1, monster_dist)) {
                visited[next_y][next_x] = true;
                predecessor[next_y][next_x] = {y, x};
                human_dist[next_y][next_x] = human_dist[y][x] + 1;
                steps[next_y][next_x] = step_vec[i];
                q.push({next_y, next_x});

                if (next_y == 0 || next_x == 0 || next_y == n-1 || next_x == m-1) {
                    end_y = next_y;
                    end_x = next_x;
                    found = true;
                }
            }
        }
    }

    if (end_y == -1) {
        cout << "NO";
        return 0;
    }

    print_steps(end_y, end_x, grid, predecessor, steps);

    return 0;
}
