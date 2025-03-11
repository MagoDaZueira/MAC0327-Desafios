#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll m, a, b, c; cin >> m >> a >> b >> c;

        ll rem1, rem2; rem1 = m; rem2 = m;

        rem1 -= a;
        if (rem1 < 0) rem1 = 0;
        rem2 -= b;
        if (rem2 < 0) rem2 = 0;

        ll t = rem1;
        rem1 -= c;
        if (rem1 < 0) rem1 = 0;
        c -= (t - rem1);

        t = rem2;
        rem2 -= c;
        if (rem2 < 0) rem2 = 0;
        c -= (t - rem1);

        cout << (m - rem1) + (m - rem2) << endl;
    }

    return 0;
}
