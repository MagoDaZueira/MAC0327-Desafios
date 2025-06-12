#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int, int> pii;

int main() {
    int n, m; cin >> n >> m;
    vector<pii> v;

    vector<int> increment(m+1, 0);
    vector<int> decrement(m+1, 0);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        increment[a]++;
        decrement[b]++;
    }

    vector<int> ans;
    int curr_increment = 0;

    for (int i = 1; i <= m; i++) {
        curr_increment += increment[i];
        if (curr_increment == 0) ans.push_back(i);
        curr_increment -= decrement[i];
    }

    cout << ans.size() << endl;
    for (auto point : ans) {
        cout << point << " ";
    }

    return 0;
}
