#include <bits/stdc++.h>

using namespace std;

#define int long long
constexpr int mod = 1e9 + 7;

int32_t main() {
#ifdef JahonaliX
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, cnt = 0, ans = 0;
    cin >> n >> k;
    vector<int> a(k), u, v;
    for (int &i : a) cin >> i, cnt += n >> i & 1;
    for (int mask = 0; mask < (1 << k); ++mask) {
        int cn = 0;
        for (int i = 0; i < k; ++i) cn += mask >> i & 1;
        if (cn != cnt) continue;
        int m = n;
        for (int i : a) m -= m & (1ll << i);
        for (int i = 0; i < k; ++i) if (mask >> i & 1) m += 1ll << a[i];
        if (m % 7) continue;
        ans = max(ans, m);
    }
    cout << ans;
    return 0;
}