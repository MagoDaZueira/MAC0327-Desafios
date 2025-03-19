#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int, int> pi;

int main() {
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> matrix(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < k; j++) {
        for (int i = 1; i < n; i++) {
            matrix[i][j] |= matrix[i-1][j];
        }
    }

    vector<vector<pi>> sorted(k, vector<pi>(n));
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n; i++) {
            sorted[j][i] = make_pair(matrix[i][j], i);
        }
    }
    for (int j = 0; j < k; j++) {
        sort(sorted[j].begin(), sorted[j].end());
    }

    while (q--) {
        int m; cin >> m;
        map<int, bool> not_valid;
        priority_queue<pi> great;
        priority_queue<pi, vector<pi>, greater<pi>> less;
        while (m--) {
            int r, c; char o;
            cin >> r >> o >> c;

            if (o == '<') {
                less.push(make_pair(r, c));
            }
            else {
                great.push(make_pair(r, c));
            }
        }
        unordered_map<int, int> l, r;
        set<ll> regions;
        while (!less.empty()) {
            int reg = less.top().first;
            r[reg] = less.top().second;
            regions.insert(reg);
            while (!less.empty() && less.top().first == reg) {
                less.pop();
            }
        }
        while (!great.empty()) {
            int reg = great.top().first;
            l[reg] = great.top().second;
            regions.insert(reg);
            while (!great.empty() && great.top().first == reg) {
                great.pop();
            }
        }

        for (auto& reg : regions) {
            // auto itl = upper_bound(sorted[reg].begin(), sorted[reg].end(), l[reg]);
            // auto itr = lower_bound(sorted[reg].begin(), sorted[reg].end(), r[reg]); itr--;
        }
    }


    return 0;
}
