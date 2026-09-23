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
    int x, a, b, y, c, d, f, s;
    cin >> x >> a >> b >> y >> c >> d;
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    f = b / x - (a - 1) / x, s = d / y - (c - 1) / y;
    if (f > s) cout << "Dilnoza " << f;
    else if (s > f) cout << "Malika " << s;
    else cout << "Durang " << f; 
    return 0;
}