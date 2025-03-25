#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

int smallest_div(int n) {
    int sq = sqrt(n);
    for (int i = 2; i <= sq + 1; i++) {
        if (n % i == 0) return i;
    }
    return n;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int div = smallest_div(n);

        int a = n / div;
        int b = n - a;

        cout << a << " " << b << endl;
    }

    return 0;
}
