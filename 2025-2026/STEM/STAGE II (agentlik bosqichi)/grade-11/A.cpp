#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define vi vector<int>

void solve()
{
    long double n, m, a, b, c, d;
    vi v;
    cin >> n >> m >> a >> b;
    long double ans = (m * (a + b) - n * a) / b;
    if (ans < 0 || ans > 10)
        cout << "Impossible";
    else
        cout << ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(3);
    int t = 1;
    cin >> t;
    while (t--)
        solve(), cout << '\n';
    return 0;
}