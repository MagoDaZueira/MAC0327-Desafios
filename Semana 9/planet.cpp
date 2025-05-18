#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int,int> pii;

const int MAXN = 200005;
const int LOG = ceil(log2(MAXN)) + 1;
vector<vector<int>> up(MAXN, vector<int>(LOG, -1));
vector<int> depth(MAXN, -1);

vector<int> cycle_id(MAXN, -1);
vector<int> tree_id(MAXN, -1);
vector<int> visited(MAXN, 0);

vector<int> tree_cycle_connection(MAXN, -1);
vector<int> cycle_pos(MAXN, -1);
vector<int> cycle_size(MAXN, -1);

const int UNVISITED = 0, ONSTACK = 1, VISITED = 2;

int n, q;

int get_depth_tree(int v, vector<int>& parent) {
    if (depth[v] != -1)    return depth[v];
    if (cycle_id[v] != -1) return depth[v] = 0;
    return depth[v] = get_depth_tree(parent[v], parent) + 1;
}

void preprocess(vector<int>& parent) {
    for (int i = 1; i <= n; i++) {
        if (tree_id[i] != -1) {
            up[i][0] = parent[i];
            get_depth_tree(i, parent);
        }
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (tree_id[i] == -1) continue;
            if (up[i][j-1] != -1) 
                up[i][j] = up[up[i][j-1]][j-1];
            else
                up[i][j] = -1;
        }
    }
}

int kth_ancestor(int x, int k) {
    if (depth[x] < k) return -1;

    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            x = up[x][j];
        }
    }

    return x;
}

int current_cycle = 0;
int current_tree = 0;

int dfs(int u, vector<int>& tp) {
    visited[u] = ONSTACK;
    int v = tp[u];
    int ret = -1;

    if (visited[v] == UNVISITED) {
        ret = dfs(v, tp);
        if (ret != -1) {
            cycle_id[u] = cycle_id[v];
        }
        else if (cycle_id[v] != -1) {
            tree_id[u] = current_tree++;
        }
        else {
            tree_id[u] = tree_id[v];
        }
        if (ret == u) ret = -1;
    }
    else if (visited[v] == ONSTACK) {
        cycle_id[u] = current_cycle++;
        if (u != v) ret = v;
    }
    else {
        if (tree_id[v] != -1) {
            tree_id[u] = tree_id[v];
        }
        else {
            tree_id[u] = current_tree++;
        }
    }

    visited[u] = VISITED;
    return ret;
}

void find_connection(int u, vector<int>& tp) {
    visited[u] = 3;
    if (cycle_id[tp[u]] != -1)
        tree_cycle_connection[tree_id[u]] = tp[u];
    else if (visited[tp[u]] != 3)
        find_connection(tp[u], tp);
}

void calc_cycle_pos(int u, int counter, vector<int>& tp) {
    visited[u] = 3;
    cycle_pos[u] = counter;
    if (visited[tp[u]] == 3) {
        cycle_size[cycle_id[u]] = counter + 1;
    }
    else {
        calc_cycle_pos(tp[u], counter + 1, tp);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vector<int> tp(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> tp[i];
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] != VISITED)
            dfs(i, tp);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] != 3) {
            if (tree_id[i] != -1 && tree_cycle_connection[tree_id[i]] == -1) {
                find_connection(i, tp);
            }
            else if (cycle_id[i] != -1) {
                calc_cycle_pos(i, 0, tp);
            }
        }
    }

    preprocess(tp);
    
    while (q--) {
        int a, b; cin >> a >> b;
        if (cycle_id[a] != -1) {
            if (cycle_id[a] != cycle_id[b]) {
                cout << -1 << endl;
                continue;
            }
            int siz = cycle_size[cycle_id[a]];
            int dist = (cycle_pos[b] - cycle_pos[a] + siz) % siz;
            cout << dist << endl;
        }
        else {
            if (cycle_id[b] != -1) {
                int root = tree_cycle_connection[tree_id[a]];
                if (cycle_id[root] != cycle_id[b]) {
                    cout << -1 << endl;
                    continue;
                }
                int siz = cycle_size[cycle_id[root]];
                int dist = (cycle_pos[b] - cycle_pos[root] + siz) % siz;
                cout << dist + depth[a] << endl;
            }
            else {
                if (tree_id[a] != tree_id[b] || depth[b] > depth[a]) {
                    cout << -1 << endl;
                    continue;
                }

                int kth = kth_ancestor(a, depth[a] - depth[b]);
                if (kth == b) cout << depth[a] - depth[b] << endl;
                else          cout << -1 << endl;
            }
        }
    }
}
