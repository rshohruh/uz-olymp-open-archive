#include <iostream>
#include <vector>
#include <algorithm>
#define all(a) (a).begin(), (a).end()
using ll = long long;
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(all(edges));
    vector<int> parent(n+1), sz(n+1);
    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
    auto find = [&](auto &&find, int u) -> int {
        if(parent[u] == u) return u;
        return parent[u] = find(find, parent[u]);
    };
 
    auto unite = [&](int u, int v) -> void {
        u = find(find, u);
        v = find(find, v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    };
    ll ans = 0;
    for(auto [w, t]: edges) {
        auto [u, v] = t;
        u = find(find, u);
        v = find(find, v);
        ans += 1ll * sz[u] * sz[v] * w;
        unite(u, v);
    }
    cout << ans;
}