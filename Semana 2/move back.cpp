#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            pq.push(make_pair(v[i], i));
        }

        vector<int> first;
        priority_queue<int, vector<int>, greater<int>> last;

        for (int i = 0; i < n; i++) {
            if (!pq.empty() && v[i] == pq.top().first) {
                pq.pop();
                
                if (!last.empty() && v[i] > last.top())
                    last.push(v[i] + 1);
                else
                    first.push_back(v[i]);

                while (!pq.empty() && pq.top().second < i) {
                    pq.pop();
                }
            }
            else {
                last.push(v[i] + 1);
            }
        }

        for (int i = 0; i < first.size(); i++) {
            cout << first[i] << " ";
        }
        while (!last.empty()) {
            cout << last.top() << " ";
            last.pop();
        }
        cout << endl;
    }

    return 0;
}
