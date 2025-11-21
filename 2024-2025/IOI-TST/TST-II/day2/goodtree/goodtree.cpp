#include <iostream>
#include <vector>
#include <functional>
using namespace std;

using ll = long long;
const ll INF = (ll)1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<ll,ll>> dp(n + 1, {-1, -1});
    vector<ll> parent(n + 1, 0);
    bool ok = true;

    function<void(ll,ll)> dfs = [&](ll u, ll p) {
        parent[u] = p;

        ll mn = -1, mx = -1;
        ll cnt_mn = 0, cnt_mx = 0;
        bool any_bad = false;

        for (ll v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);

            if (dp[v].second == -1) any_bad = true;

            if (dp[v].second == mx) cnt_mx++;
            if (dp[v].second > mx) {
                mx = dp[v].second;
                cnt_mx = 1;
            }

            if (dp[v].first == mn) cnt_mn++;
            if (dp[v].first > mn) {
                mn = dp[v].first;
                cnt_mn = 1;
            }
        }

        if (cnt_mn > 1 && mn != -1) mn++;
        if (cnt_mx > 1 && mx != -1) mx++;

        if (any_bad) mx = -1;

        if (a[u] != -1 && ((mn != -1 && a[u] < mn) || (mx != -1 && a[u] > mx))) {
            ok = false;
        }

        if (a[u] == -1) {
            dp[u] = {max(mn, 0LL), mx};
        } else {
            dp[u] = {a[u], a[u]};
        }
    };

    function<void(ll,ll,ll)> dfs2 = [&](ll u, ll p, ll need) {
        a[u] = need;

        ll chosen = -1;

        for (ll v : adj[u]) {
            if (v == p) continue;
            if (dp[v].first <= need && need <= dp[v].second) chosen = v;
            if (dp[v].first == need) {
                chosen = v;
                break;
            }
        }

        if (chosen != -1) {
            for (ll v : adj[u]) {
                if (v == p) continue;
                if (v == chosen) dfs2(v, u, need);
                else dfs2(v, u, dp[v].first);
            }
        } else {
            for (ll v : adj[u]) {
                if (v == p) continue;
                dfs2(v, u, dp[v].second);
            }
        }
    };

    dfs(1, 0);

    for (ll i = 1; i <= n; ++i)
        if (dp[i].second == -1) dp[i].second = INF;

    if (!ok) {
        cout << "NO\n";
        return 0;
    }

    dfs2(1, 0, dp[1].first);

    cout << "YES\n";
    for (ll i = 1; i <= n; ++i)
        cout << a[i] << " ";

    return 0;
}
