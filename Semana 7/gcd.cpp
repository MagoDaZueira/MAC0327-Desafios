#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, m;
int turn = 1;
const int MAX_N = 100;
const int MAX_M = 100;
vector<vector<int>> a(MAX_N, vector<int>(MAX_M));
vector<vector<int>> visited(MAX_N, vector<int>(MAX_M, 0));

vector<int> all_divisors(int x) {
    vector<int> divs;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i != x / i) divs.push_back(x / i);
        }
    }
    sort(divs.rbegin(), divs.rend());
    return divs;
}

bool dfs(int i, int j, int divisor) {
    if (i == n-1 && j == m-1) return true;
    visited[i][j] = turn;

    bool possible = false;
    if (i+1 < n && visited[i+1][j] != turn && a[i+1][j] % divisor == 0)              possible = possible || dfs(i+1, j, divisor);
    if (j+1 < m && visited[i][j+1] != turn && a[i][j+1] % divisor == 0 && !possible) possible = possible || dfs(i, j+1, divisor);
    
    return possible;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int divisor = gcd(a[0][0], a[n-1][m-1]);
    vector<int> divs = all_divisors(divisor);

    for (auto div : divs) {
        bool possible = dfs(0, 0, div);
        turn++;
        if (possible) {
            cout << div << endl;
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
