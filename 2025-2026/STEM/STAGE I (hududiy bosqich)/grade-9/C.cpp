#include <bits/stdc++.h>

using namespace std;

#define int long long
constexpr int mod = 1e9 + 7;

int binpow(int x, int y, int m) {
    if (!y) return 1;
    int z = binpow(x, y >> 1, m);
    if (z == -1) return -1;
    if (m / z < z) return -1;
    z = z * z;
    if (y & 1) {
        if (m / x < z) return -1;
        z = z * x;
    }
    return z;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int &i : x) cin >> i;
        vector<int> v;
    for (int i : x) {
        for (int pw = 2; pw < 62; ++pw) {
            int l = 1, r = m + 1;
            while (l + 1 < r) {
                int md = (l + r) >> 1, k;
                k = binpow(md, pw, m);
                if (~k && k <= i) l = md;
                else r = md;
            }
            int k = 1;
            for (int j = 0; j < pw; ++j) k *= l;
            v.emplace_back(k);
            k = m;
            l++;
            for (int j = 0; j < pw; ++j) k /= l;
            if (k) {
                k = 1;
                for (int j = 0; j < pw; ++j) k *= l;
                v.emplace_back(k);
            }
        }
        int mn = LLONG_MAX, l = -1;
        for (int j : v) {
            if (j > m) continue;
            int nw = abs(j - i);
            if (mn > nw) mn = nw, l = j;
            if (mn == nw) l = min(l, j);
        }
        cout << l << '\n';
        v.clear();
    }
    return 0;
}