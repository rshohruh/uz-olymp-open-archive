#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), len(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        len[i] = to_string(a[i]).size();
    }

    vector<int> pow10(18, 1);
    for (int i = 1; i < 18; ++i)
        pow10[i] = (1LL * pow10[i - 1] * 10) % k;

    vector<unordered_map<int,int>> mp(11), mp2(11);
    ll ans = 0;

    auto modify = [&](int x, int l, int delta) {
        x %= k;

        if (delta == 1) {
            mp2[l][x]++;
            for (int j = 0; j <= 10; ++j)
                mp[j][1LL * pow10[j] * x % k]++;
        }

        auto it = mp[l].find((k - x) % k);
        if (it != mp[l].end()) ans += it->second * delta;

        for (int j = 0; j <= 10; ++j) {
            int need = (k - (1LL * pow10[j] * x % k)) % k;
            auto it2 = mp2[j].find(need);
            if (it2 != mp2[j].end()) ans += it2->second * delta;
        }

        if ((1LL * pow10[l] * x % k + x) % k == 0)
            ans -= delta;

        if (delta == -1) {
            auto it2 = mp2[l].find(x);
            if (--it2->second == 0) mp2[l].erase(it2);

            for (int j = 0; j <= 10; ++j) {
                auto it3 = mp[j].find(1LL * pow10[j] * x % k);
                if (--it3->second == 0) mp[j].erase(it3);
            }
        }
    };

    for (int i = 1; i <= n; ++i)
        modify(a[i], len[i], 1);

    int q;
    cin >> q;

    while (q--) {
        int idx, x;
        cin >> idx >> x;

        modify(a[idx], len[idx], -1);
        a[idx] = x;
        len[idx] = to_string(x).size();
        modify(a[idx], len[idx], 1);

        cout << ans << "\n";
    }

    return 0;
}
