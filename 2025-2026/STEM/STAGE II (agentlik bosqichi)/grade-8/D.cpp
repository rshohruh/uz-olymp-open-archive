#include "bits/stdc++.h"
using namespace std;
#define int int64_t

int32_t main() {
#ifdef khba
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector <int> a(n);
    for (int &i : a) cin >> i;
    int ans = 0, cnt = 0;
    for (int l = 0, r = 0; r < n; ++r) {
        if (r) cnt += a[r - 1] > a[r];
        while (cnt > k) {
            cnt -= a[l + 1] < a[l];
            l += 1;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}