#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        string s; cin >> s;
        int n = s.size();

        int big, big_pos;
        for (int i = 0; i < n; i++) {
            big = s[i];
            big_pos = i;

            int last = min(n - 1, i + 8);
            for (int j = i+1; j <= last; j++) {
                int actual = s[j] - (j - i);
                if (actual > big) {
                    big = actual;
                    big_pos = j;
                }
            }
            for (int j = big_pos; j > i; j--) {
                s[j]--;
                swap(s[j], s[j-1]);
            }
        }

        cout << s << endl;
    }

    return 0;
}
