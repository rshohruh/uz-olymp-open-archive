#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ar array

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n], mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    mx = (mx - 1) / 2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] <= mx;
    }
    cout << ans;
}