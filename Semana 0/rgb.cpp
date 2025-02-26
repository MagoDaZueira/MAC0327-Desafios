#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    string s;

    while (t--) {
        cin >> s;
        map<char, bool> found;
        bool yes = true;

        for (int i = 0; i < 6; i++) {
            if (s[i] > 'a') {
                found[s[i]] = true;
            }
            else if (!found[s[i] + 32]) {
                yes = false;
                break;
            }
        }

        if (yes) cout << "YES" << endl;
        else     cout << "NO"  << endl;
    }

    return 0;
}
