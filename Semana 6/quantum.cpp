#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n, s; cin >> n >> s;
    ll sum = 0;
    ll ans = 0;
    priority_queue<int> pq;

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
        pq.push(temp);
    }

    int biggest;
    int half;
    while (sum > s) {
        biggest = pq.top();
        pq.pop();
        half = biggest / 2;
        pq.push(half);
        sum -= (biggest - half);
        ans++;
    }

    cout << ans;

    return 0;
}
