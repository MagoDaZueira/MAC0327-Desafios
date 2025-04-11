#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    int i;
    for (i = 0; i < m; i++) {
        if (i >= n) {
            cout << "YES" << endl;
            return;
        }
        if (s[i] == 'L' || i == m-1) {
            break;
        }
    }

    int cold = 0;
    while (true) {
        if (cold > k) {
            cout << "NO" << endl;
            return;
        }
        if (i >= n) {
            cout << "YES" << endl;
            return;
        }
        if (s[i] == 'C') {
            cout << "NO" << endl;
            return;
        }
        
        else if (s[i] == 'L') {
            for (int j = i+1; j-i <= m; j++) {
                if (j >= n) {
                    cout << "YES" << endl;
                    return;
                }
                if (s[j] == 'L' || j-i == m) {
                    i = j;
                    break;
                }
            }
        }

        else if (s[i] == 'W') {
            cold++;
            i++;
        }
    }
}
 
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
