#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define vi vector<int>

struct node
{
    int x = 0, i = 0;
};

vector<int> t;

int n, q;
vector<int> v;
void build(int l = 0, int r = n - 1, int i = 1)
{
    if (l == r)
        t[i] = v[l];
    else
    {
        int m = (l + r) / 2;
        build(l, m, i * 2);
        build(m + 1, r, i * 2 + 1);
        t[i] = max(t[i * 2], t[i * 2 + 1]);
    }
}

void upd(int pos, int x, int l = 0, int r = n - 1, int i = 1)
{
    if (l == r)
        t[i] -= x;
    else
    {
        int m = (l + r) / 2;
        if (pos <= m)
            upd(pos, x, l, m, i * 2);
        else
            upd(pos, x, m + 1, r, i * 2 + 1);
        t[i] = max(t[i * 2], t[i * 2 + 1]);
    }
}

int walk(int x, int j, int l = 0, int r = n - 1, int i = 1)
{
    if (r < j || t[i] < x)
        return -1;
    if (l == r)
        return l;
    int m = (l + r) / 2;
    int got = walk(x, j, l, m, i * 2);
    if (got != -1)
        return got;
    return walk(x, j, m + 1, r, i * 2 + 1);
}

void solve()
{
    cin >> n >> q;
    v.resize(n);
    t.resize(4 * n);
    for (auto &i : v)
        cin >> i;
    build();
    while (q--)
    {
        int t, x;
        cin >> t >> x;
        int i = walk(x, 0);
        int j = (i >= 0 && i < n - 1 ? walk(x, i + 1) : -1);
        if (i == -1 || j == -1)
            cout << -1;
        else
        {
            cout << (i + j + 2) * 2;
            if (t)
                cout << ' ' << v[i] << ' ' << v[j], v[i] -= x, v[j] -= x, upd(i, x), upd(j, x);
        }
        cout << '\n';
    }
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