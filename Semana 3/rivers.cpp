#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void query(vector<vector<int>>& matrix) {
    int m; cin >> m;
    int small = INT_MIN, big = INT_MAX;
    bool possible = true;
    while (m--) {
        int r, c; char o;
        cin >> r >> o >> c;

        if (o == '<') {
            auto it = lower_bound(matrix[r-1].begin(), matrix[r-1].end(), c);

            if (it == matrix[r-1].begin()) possible = false;
            else big = min(big, (int)distance(matrix[r-1].begin(), it) - 1);
        }

        else {
            auto it = upper_bound(matrix[r-1].begin(), matrix[r-1].end(), c);

            if (it == matrix[r-1].end()) possible = false;
            else small = max(small, (int)distance(matrix[r-1].begin(), it));
        }

        if (small > big && small != INT_MIN && big != INT_MAX) {
            possible = false;
        }
    }

    if (possible) cout << max(1, small + 1) << endl;
    else          cout << -1 << endl;
}

int main() {
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> matrix(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> matrix[j][i];
        }
    }

    for (int j = 0; j < k; j++) {
        for (int i = 1; i < n; i++) {
            matrix[j][i] |= matrix[j][i-1];
        }
    }

    while (q--) {
        query(matrix);
    }

    return 0;
}
