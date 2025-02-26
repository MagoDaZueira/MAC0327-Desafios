#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    bool grid[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int white, black;
    ll total = 0;

    for (int i = 0; i < n; i++) {
        white = 0; black = 0;

        for (int j = 0; j < m; j++) {
            white += !grid[i][j];
            black += grid[i][j];
        }
        total += (1LL << white) - 1;
        total += (1LL << black) - 1;
    }

    for (int j = 0; j < m; j++) {
        white = 0; black = 0;

        for (int i = 0; i < n; i++) {
            white += !grid[i][j];
            black += grid[i][j];
        }
        total += (1LL << white) - 1;
        total += (1LL << black) - 1;
    }

    total -= n * m;
    cout << total;

    return 0;
}
