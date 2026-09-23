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
    int t;
    cin >> t;
    while (t--) {
        int x, l, r;
        cin >> x >> l >> r;
        if (abs(x - l) >= l && abs(x - l) <= r) cout << l << ' ' << x - l << '\n';
        else if (abs(x - r) >= l && abs(x - r) <= r) cout << r << ' ' << x - r << '\n';
        else if (abs(x + l) >= l && abs(x + l) <= r) cout << -l << ' ' << x + l << '\n';
        else if (abs(x + r) >= l && abs(x + r) <= r) cout << -r << ' ' << x + r << '\n';
        else cout << "impossible\n";
    }
    return 0;
}