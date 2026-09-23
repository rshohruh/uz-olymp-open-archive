#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define line '\n'

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        v[i] = c - '0';
    }
    int cur = 0, ans = 0;
    for (int &i : v) {
        int need = 3 - (i + cur) % 3;
        if (need == 3) need = 0;
        ans += need;
        cur += need;
    }
    cout << ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t = 1;
    while (t--) {
        solve();
        cout << line;
    }
}