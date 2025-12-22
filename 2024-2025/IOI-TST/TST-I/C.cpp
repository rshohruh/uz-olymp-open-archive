#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 2e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n + 1);
    const int lg = 18;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<vector<int>> par(lg, vector<int>(n + 1, -1));
    vector<int> height(n + 1), tin(n + 1), tout(n + 1);
    int z = 0;
    auto dfs = [&](auto &dfs, int u) -> void {
        for (int i = 1; i < lg and u > 1; i++) {
            par[i][u] = par[i - 1][par[i - 1][u]];
            if (par[i][u] == -1) break;
        }
        tin[u] = z++;
        for (int v: g[u]) {
            if (par[0][u] == v) continue;
            par[0][v] = u;
            height[v] = height[u] + 1;
            dfs(dfs, v);
        }
        tout[u] = z++;
    };
    dfs(dfs, 1);
    auto isPar = [&](int u, int v) -> bool {
        return tin[u] <= tin[v] and tout[v] <= tout[u];
    };
    auto lca = [&](int u, int v) -> int {
        if (tin[u] <= tin[v] and tout[v] <= tout[u]) return u;
        swap(u, v);
        if (tin[u] <= tin[v] and tout[v] <= tout[u]) return u;
        for (int i = lg - 1; i >= 0; i--) {
            if (par[i][u] != -1 and !isPar(par[i][u], v)) {
                u = par[i][u];
            }
        }
        return par[0][u];
    };
    auto get = [&](auto &get, int u, int v, int k, bool can) -> int {
        if (u == v) return 0;
        int dist = height[u] + height[v] - 2 * height[lca(u, v)];
        if (dist != k) return 1;
        if (dist > 1) return 2;
        bool found = false;
        for (int _ = 0; _ < 2; _++) {
            for (int x: g[u]) {
                if (x == v) continue;
                if (g[x].size() > 1) return 2;
            }
            swap(u, v);
        }
        if (!can) return -1;
        return (g[u].size() > 1 and g[v].size() > 1) ? 3 : -1;
    };
    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;
        cout << get(get, u, v, k, true) << '\n';
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int queries = 1;
    // cin >> queries;

	for (int test_case = 1; test_case <= queries; test_case++) {
		solve();
		cout << '\n';
	}
}