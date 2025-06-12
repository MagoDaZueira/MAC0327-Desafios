#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int, int> pii;

int main() {
    int x, n; cin >> x >> n;
    set<int> p;
    vector<int> p_vec(n);

    for (int i = 0; i < n; i++) {
        int pi; cin >> pi;
        p.insert(pi);
        p_vec[i] = pi;
    }

    int largest = 0;
    int last = 0;
    for (auto light : p) {
        largest = max(largest, light - last);
        last = light;
    }
    largest = max(largest, x - last);

    vector<int> ans(n+1);
    ans[n] = largest;

    for (int i = n - 1; i > 0; i--) {
        auto it = p.find(p_vec[i]);
        int l = it == p.begin() ? 0 : *prev(it);
        int r = next(it) == p.end() ? x : *next(it);
        largest = max(largest, r - l);
        ans[i] = largest;
        p.erase(it);
    }

    for (int i = 1; i <= n; i++) {
        cout << max(0, ans[i]) << " ";
    }

    return 0;
}
