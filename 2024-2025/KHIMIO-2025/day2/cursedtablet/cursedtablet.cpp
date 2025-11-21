#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
int k;

pair<bool, vector<vector<ll>>> get(vector<ll> a, vector<ll> b, int n, int k, bool rev)
{
    vector<vector<ll>> res;
    if (rev)
    {
        res.push_back(vector<ll>(1, 2));
        reverse(a.begin(), a.end());
    }
    vector<ll> ps(n, 0);
    for (int i = 0; i <= n - k; ++i)
    {
        if (i)
            ps[i] += ps[i - 1];
        if (ps[i] + a[i] != b[i])
        {
            ll x = b[i] - (ps[i] + a[i]);
            res.push_back(vector<ll>{1, i + 1, i + k, x});
            ps[i] += x;
            if (i + k < n)
                ps[i + k] -= x;
        }
    }
    for (int i = n - k + 1; i < n; ++i)
    {
        ps[i] += ps[i - 1];
        if (a[i] + ps[i] != b[i])
        {
            res.clear();
            return make_pair(false, res);
        }
    }
    return make_pair(true, res);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        if (i)
            cout << '\n';
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);

        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        auto res1 = get(a, b, n, k, false);
        auto res2 = get(a, b, n, k, true);

        if (!res1.first && !res2.first)
        {
            cout << -1 << '\n';
        }
        else
        {
            auto res = !res1.first ? res2.second : !res2.first                           ? res1.second
                                               : res1.second.size() < res2.second.size() ? res1.second
                                                                                         : res2.second;
            cout << res.size() << '\n';
            for (auto x : res)
            {
                // for(auto y:x) cout << y << ' ';
                cout << x[0];
                for (int j = 1; j < x.size(); ++j)
                    cout << ' ' << x[j];
                cout << '\n';
            }
        }
    }
    return 0;
}