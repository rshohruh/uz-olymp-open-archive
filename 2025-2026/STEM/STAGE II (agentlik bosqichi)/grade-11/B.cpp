#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define vi vector<int>

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first, v[i].second = i;
    sort(all(v));
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (v[j].first < v[i].first)
            j++;
        ans += v[i].first == j;
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