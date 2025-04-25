#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int d = 0;
    
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
        d++;
        while (pq.top() < d) {
            pq.pop();
            d--;
        }
        cout << pq.size() << " ";
    }

    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
