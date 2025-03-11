#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    map<int, bool> found;
    stack<int> s;
    
    for (int i = n-1; i >= 0; i--) {
        if (!found[v[i]]) {
            s.push(v[i]);
            found[v[i]] = true;
        }   
    }

    cout << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
