#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

using ll = int;

void build_bits(const vector<ll> &col, bitset<2001> &asc, bitset<2001> &desc) {
    int n = col.size();
    for (int i = 1; i < n; ++i) {
        if (col[i] >= col[i - 1]) asc.set(i);
        if (col[i] <= col[i - 1]) desc.set(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            cin >> a[i][j];

    vector<pair<bitset<2001>, bitset<2001>>> info(m);

    for (ll j = 0; j < m; ++j) {
        vector<ll> col(n);
        for (ll i = 0; i < n; ++i) col[i] = a[i][j];
        build_bits(col, info[j].first, info[j].second);
    }

    bitset<2001> need;
    for (ll i = 1; i < n; ++i) need.set(i);

    vector<ll> used(m, 0);
    vector<pair<ll, ll>> order;
    vector<ll> current;

    while (need.count()) {
        current.clear();

        for (ll j = 0; j < m; ++j) {
            if (used[j]) continue;

            if ((info[j].first & need) == need) {
                used[j] = 1;
                current.push_back(j);
                order.push_back({j + 1, 1});
            }
            else if ((info[j].second & need) == need) {
                used[j] = 1;
                current.push_back(j);
                order.push_back({j + 1, -1});
            }
        }

        if (current.empty()) break;

        for (ll i = 1; i < n; ++i) {
            if (!need[i]) continue;

            bool diff = false;
            for (ll j : current) {
                if (a[i][j] != a[i - 1][j]) {
                    diff = true;
                    break;
                }
            }
            if (diff) need.reset(i);
        }
    }

    for (auto [col, type] : order) {
        cout << col << " " << (type == 1 ? "asc" : "desc") << "\n";
    }

    for (ll j = 0; j < m; ++j) {
        if (!used[j]) {
            cout << j + 1 << " desc\n";
        }
    }

    return 0;
}
