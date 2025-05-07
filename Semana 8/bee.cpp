#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;

const int DIR_SIZE = 6;
pii dir[2][DIR_SIZE] = {
    {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, -1}},
    {{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, 1}}
};

int n, m;

bool is_valid(int y, int x, vector<vector<bool>>& visited) {
    return (y >= 0 && y < n && x >= 0 && x < m && !visited[y][x]);
}

int main() {
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    deque<pii> dq;

    for (int j = 0; j < m; j++) {
        visited[0][j] = true;
        if (grid[0][j] == '.') {
            dist[0][j] = 1;
            dq.push_back({0, j});
        }
        else {
            dist[0][j] = 0;
            dq.push_front({0, j});
        }
    }

    while (!dq.empty()) {
        auto [y, x] = dq.front();
        dq.pop_front();

        if (y == n-1) {
            cout << dist[y][x];
            return 0;
        }
        
        for (int i = 0; i < DIR_SIZE; i++) {
            int next_y = y + dir[y%2][i].first;
            int next_x = x + dir[y%2][i].second;

            if (is_valid(next_y, next_x, visited)) {
                visited[next_y][next_x] = true;

                if (grid[next_y][next_x] == '.') {
                    dist[next_y][next_x] = dist[y][x] + 1;
                    dq.push_back({next_y, next_x});
                }
                else {
                    dist[next_y][next_x] = dist[y][x];
                    dq.push_front({next_y, next_x});
                }
            }
        }
    }

    return 0;
}
