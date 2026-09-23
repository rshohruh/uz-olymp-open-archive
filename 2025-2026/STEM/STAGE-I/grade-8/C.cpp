#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define line '\n'

void solve() {
    int n, x; cin >> n >> x;
    int ans = 0, res = 1e9;
    int c = 0;
    while (x > n) {
        res = min(res, x-n + c);
        if (x % 2) {
            x--;
            ans++;
            c++;
        } else {
            x >>= 1;
            ans++;
            c+=2;
        }
    }
    ans++;
    res = min(res,c);
    cout << ans << ' ' << res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t = 1;
    while (t--) {
        solve();
        cout << line;
    }
}