#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + a[i + 1] > x) {
            int need = a[i] + a[i + 1] - x;
            int can = min(a[i + 1], need);
            a[i + 1] -= can;
            ans += need;
        }
    }
    cout << ans;
}