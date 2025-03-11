#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a; cin >> a;
        stack<char> b;

        for (int i = 0; i < a.size(); i++) {
            if      (a[i] == 'q') b.push('p');
            else if (a[i] == 'p') b.push('q');
            else                  b.push('w');
        }

        while (!b.empty()) {
            cout << b.top();
            b.pop();
        }

        cout << endl;
    }

    return 0;
}
