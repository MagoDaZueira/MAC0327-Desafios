#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    multiset<int> sneakers;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        sneakers.insert(temp);
    }

    int minimum;
    while (q--) {
        cin >> minimum;
        auto it = sneakers.lower_bound(minimum);

        if (it != sneakers.end()) {
            cout << *it << endl;
            sneakers.erase(it);
        }

        else {
            cout << -1 << endl;
        }
    }

    return 0;
}
