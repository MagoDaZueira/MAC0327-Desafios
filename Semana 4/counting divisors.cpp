#include <iostream>
#include <vector>
#include <cmath>
#define ll long long int
using namespace std;

int count_div(int n) {
    int sq = sqrt(n);
    int count = 0;
    for (int i = 1; i <= sq; i++) {
        if (n % i == 0) { 
            count++;
            if (i != n / i) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n; cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << count_div(x) << endl;
    }

    return 0;
}
