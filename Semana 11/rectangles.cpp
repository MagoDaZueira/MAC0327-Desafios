#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

pii choose_point(vector<tiii>& x, vector<tiii>& y, int excluded, int n) {
    int x_comp = -1, y_comp = -1;
    int amount = 0;

    // cout << "Ignored: " << excluded << endl;
    // cout << "Ponto X:\n";
    for (auto [p, is_a, id] : x) {
        // cout << "p: " << p << " | a: " << is_a << " | id: " << id << " | amount: " << amount << endl;
        if (id == excluded) continue;
        if (is_a) amount++;
        else amount--;
        if (amount == n - 1) {
            x_comp = p;
            break;
        }
    }

    amount = 0;
    // cout << "Ponto Y\n";
    for (auto [p, is_a, id] : y) {
        // cout << "p: " << p << " | a: " << is_a << " | id: " << id << " | amount: " << amount << endl;
        if (id == excluded) continue;
        if (is_a) amount++;
        else amount--;
        if (amount == n - 1) {
            y_comp = p;
            break;
        }
    }

    return {x_comp, y_comp};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<tiii> x;
    vector<tiii> y;

    for (int i = 0; i < n; i++) {
        int xa, xb, ya, yb; cin >> xa >> ya >> xb >> yb;
        x.push_back({xa, 1, i});
        x.push_back({xb+1, 0, i});
        y.push_back({ya, 1, i});
        y.push_back({yb+1, 0, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    set<int> outside;
    for (int i = 0; i < n; i++) outside.insert(i);

    set<int> x_out;
    set<int> y_out;
    int amount_n = 0;

    // cout << "X:" << endl;
    for (auto [p, is_a, id] : x) {
        if (is_a) outside.erase(id);
        else outside.insert(id);
        // cout << "p: " << p << " | a: " << is_a << " | id: " << id << " | sz: " << outside.size() << endl;
        if (outside.size() == 0) {
            amount_n++;
            break;
        } 
        if (outside.size() == 1) {
            x_out.insert(*outside.begin());
        }
    }

    outside.clear();
    for (int i = 0; i < n; i++) outside.insert(i);

    // cout << "Y:" << endl;
    for (auto [p, is_a, id] : y) {
        if (is_a) outside.erase(id);
        else outside.insert(id);
        // cout << "p: " << p << " | a: " << is_a << " | id: " << id << " | sz: " << outside.size() << endl;
        if (outside.size() == 0) {
            amount_n++;
            break;
        } 
        if (outside.size() == 1) {
            y_out.insert(*outside.begin());
        }
    }

    if (amount_n == 2) {
        // cout << "a" << endl;
        pii ans = choose_point(x, y, 0, n);
        cout << ans.first << " " << ans.second << endl;
        return 0;
    }

    else if (amount_n == 1) {
        // cout << "b" << endl;
        int ignored = x_out.empty() ? *y_out.begin() : *x_out.begin();
        pii ans = choose_point(x, y, ignored, n);
        cout << ans.first << " " << ans.second << endl;
        return 0;
    }

    set<int> concat;
    int ignored = -1;
    for (auto id : x_out) {
        concat.insert(id);
    }
    for (auto id : y_out) {
        auto ret = concat.insert(id);
        if (!ret.second) {
            ignored = id;
            break;
        }
    }

    // cout << "c" << endl;

    pii ans = choose_point(x, y, ignored, n);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
