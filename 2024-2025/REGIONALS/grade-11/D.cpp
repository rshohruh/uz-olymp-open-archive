#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;

const ll INF = 5 * 1e18;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> al(3);
    string abc = "ABC";
    for (int i = 0; i < 2 * n; i++) {
        ll x; char c;
        cin >> x >> c;
        al[abc.find(c)].pb(x);
    }
    vector<int> odd;
    for (int i = 0; i < 3; i++) {
        sort(all(al[i]));
        if (((int) al[i].size()) & 1) {
            odd.pb(i);
        }
    }
    if (odd.empty()) {
        cout << 0;
        return;
    }
    int even = 3 - odd[0] - odd[1];
    ll ans = INF;
    for (auto x : al[odd[0]]) {
        auto it = lower_bound(all(al[odd[1]]), x);
        if (it != al[odd[1]].end()) {
            mins(ans, *it - x);
        }
        if (it != al[odd[1]].begin()) {
            it--;
            mins(ans, x - *it);
        }
    }
    int sz = al[even].size();
    if (!sz) {
        cout << ans;
        return;
    }
    vector<vector<ll>> mn(sz, vector<ll> (2, INF));
    for (int i = 0; i < sz; i++) {
        ll x = al[even][i];
        for (int j = 0; j < 2; j++) {
            auto it = lower_bound(all(al[odd[j]]), x);
            if (it != al[odd[j]].end()) {
                mins(mn[i][j], *it - x);
            }
            if (it != al[odd[j]].begin()) {
                it--;
                mins(mn[i][j], x - *it);
            }
        }
    }
    vector<vector<ll>> pre(sz, vector<ll> (2)), suf(sz, vector<ll> (2));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < 2; j++) {
            pre[i][j] = min((i == 0 ? INF : pre[i - 1][j]), mn[i][j]);
            int z = sz - i - 1;
            suf[z][j] = min((z == sz - 1 ? INF : suf[z + 1][j]), mn[z][j]);
        }
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < 2; j++) {
            ll can = INF;
            if (i > 0) {
                mins(can, pre[i - 1][1 - j]);
            }
            if (i + 1 < sz) {
                mins(can, suf[i + 1][1 - j]);
            }
            mins(ans, can + mn[i][j]);
        }
    }
    cout << ans;
}