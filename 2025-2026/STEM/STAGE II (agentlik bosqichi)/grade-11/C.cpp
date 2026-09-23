#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define vi vector<int>

void solve()
{
    int n, ans = 1;
    cin >> n;
    while (n > 1)
    {
        ans += n;
        int l = 0, r = n, cur = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m * (m + 1) / 2 < n)
                cur = m, l = m + 1;
            else
                r = m - 1;
        }
        int diff = n - cur * (cur + 1) / 2;
        int first = cur * (cur - 1) / 2 + 1;
        n = first + min(diff, cur) - 1;
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(2);
    int t = 1;
    // cin >> t;
    while (t--)
        solve(), cout << '\n';
    return 0;
}