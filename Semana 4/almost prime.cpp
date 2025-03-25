#include <iostream>
using namespace std;

int is_almost(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) count++; 
    return count == 2;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += is_almost(i);
    }

    cout << ans;
    return 0;
}
