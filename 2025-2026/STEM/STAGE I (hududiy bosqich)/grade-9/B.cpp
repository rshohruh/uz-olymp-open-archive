#include <bits/stdc++.h>

using namespace std;

#define int long long
constexpr int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k, s;
        cin >> n >> k;
        if (n == 1) {
            cout << k << '\n';
            continue;
        }
        s = k / (n * 2 - 2) * (n * (n + 1) - n - 1);
        k %= n * 2 - 2;
        if (k < n) {
            s += k * (k + 1) / 2;
        }
        else {
            k -= n - 1;
            s += n * (n - 1) / 2;
            k = n - k;
            s += n * (n + 1) / 2 - k * (k + 1) / 2;
        }
        cout << s << '\n';
    }
    return 0;
}