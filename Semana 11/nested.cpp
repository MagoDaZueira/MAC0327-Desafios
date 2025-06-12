#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int, int> pii;

int main() {
    int n; cin >> n;
    vector<tuple<int,int,int>> v;
    vector<pii> id_to_range(n);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, 1, i});
        v.push_back({b, 0, i});
        id_to_range[i] = {a, b};
    }

    sort(v.begin(), v.end());

    vector<int> inside(n, 0);
    vector<int> outside(n, 0);

    // =============== Verifica quem tá contido ===============
    int same_b = 0;
    int curr_b = 0;
    int last_a = 0;
    vector<int> to_push;

    for (auto [x, is_a, id] : v) {
        auto [a, b] = id_to_range[id];
        if (is_a) {
            if (last_a != x) {
                for (int id_i : to_push) {
                    auto [ai, bi] = id_to_range[id_i];
                    if (bi < curr_b || same_b > 1) {
                        inside[id_i] = 1;
                    }
                }
                to_push.clear();
                last_a = x;
            }
            to_push.push_back(id);
            if (curr_b == b) same_b++;
            else if (b > curr_b) {
                curr_b = b;
                same_b = 1;
            }
        }
    }

    for (int id_i : to_push) {
        auto [ai, bi] = id_to_range[id_i];
        if (bi < curr_b || same_b > 1) {
            inside[id_i] = 1;
        }
    }
    to_push.clear();

    // ================= Verifica quem contém =================
    auto cmp = [](const pii& a, const pii& b) {
        return a > b;
    };
    set<pii, decltype(cmp)> big_b(cmp);
    last_a = 0;

    for (auto [x, is_a, id] : v) {
        auto [a, b] = id_to_range[id];
        if (is_a) {
            if (last_a != x) {
                for (int id_i : to_push) {
                    auto [ai, bi] = id_to_range[id_i];
                    for (auto it = big_b.begin(); it != big_b.end();) {
                        auto [out_b, id_b] = *it;
                        if (id_b == id_i) ++it;
                        else if (bi <= out_b) {
                            outside[id_b] = 1;
                            it = big_b.erase(it);
                        }
                        else break;
                    }
                }
                to_push.clear();
                last_a = x;
            }
            to_push.push_back(id);
            big_b.insert({b, id});
        }
    }

    for (int id_i : to_push) {
        auto [ai, bi] = id_to_range[id_i];
        for (auto it = big_b.begin(); it != big_b.end();) {
            auto [out_b, id_b] = *it;
            if (id_b == id_i) ++it;
            else if (bi <= out_b) {
                outside[id_b] = 1;
                it = big_b.erase(it);
            }
            else break;
        }
    }

    for (auto o : outside) {
        cout << o << " ";
    }
    cout << endl;
    for (auto i : inside) {
        cout << i << " ";
    }

    return 0;
}
