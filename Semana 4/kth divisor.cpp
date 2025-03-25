// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long int
using namespace std;

void divisors(ll n, vector<ll>& divs) {
    ll sq = sqrt(n);
    for (int i = 1; i < sq; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n/i);
        }
    }
    if (n % sq == 0) {
        divs.push_back(sq);
        if (n / sq != sq) divs.push_back(n / sq);
    }
}

int main() {
    ll n, k; cin >> n >> k;

    if (k > 1e7) {
        cout << -1;
        return 0;
    }

    vector<ll> divs;
    divisors(n, divs);

    sort(divs.begin(), divs.end());

    if (k <= divs.size()) {
        cout << divs[k-1];
    }
    else {
        cout << -1;
    }

    return 0;
}
