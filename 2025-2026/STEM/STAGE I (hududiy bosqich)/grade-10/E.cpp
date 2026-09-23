#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
vector<pair<int,int>> adj[N]; 
int r[N], par[N];
bool used[N], vis[N];
pair<int,int> ans[N];

void dfs(int v) {
    vis[v] = true;
    for (auto [to, id] : adj[v]) {
        if (used[id]) continue;
        used[id] = true;

        if (!vis[to]) dfs(to);

        if (par[to] == 1) {
            ans[id] = {to, v};
            par[to] ^= 1;
        } else {
            ans[id] = {v, to};
            par[v] ^= 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        sum += r[i];
    }

    if (sum % 2 != m % 2) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (par[i] != r[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}