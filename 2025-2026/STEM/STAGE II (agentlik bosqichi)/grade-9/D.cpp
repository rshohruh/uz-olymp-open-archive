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
    int n, ans;
    cin >> n, ans = n;
    vector<int> a(n), dp(n), p(n), cnt(n);
    for (int &i : a) cin >> i, i--;
    for (int i = 0; i < n; ++i) p[a[i]] = i;
    for (int i = 1; i < n; ++i) dp[i] = dp[i - 1] + (p[i] < p[i - 1]), ans += dp[i];
    cout << ans;
    return 0;
}