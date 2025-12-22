#include <bits/stdc++.h>
#define ar array
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
vector <int> t[maxn << 2];
int qx, ql, qr, b[maxn];
ll n, k, ans = 0;

void build(int v = 1, int l = 0, int r = n - 1) {
    if (l == r)
        return t[v] = {b[l]}, void();
    int m = l + r >> 1;
    build(v << 1, l, m);
    build(v << 1 | 1, m + 1, r);
    int i = 0, j = 0, c1 = v << 1, c2 = v << 1 | 1;
    for (; i < t[c1].size() && j < t[c2].size(); ) {
        if (t[c1][i] < t[c2][j])
            t[v].emplace_back(t[c1][i++]);
        else
            t[v].emplace_back(t[c2][j++]);
    }
    for (; i < t[c1].size(); i++)
        t[v].emplace_back(t[c1][i]);
    for (; j < t[c2].size(); j++)
        t[v].emplace_back(t[c2][j]);
}

int get(int v = 1, int l = 0, int r = n - 1) {
    if (l > r || qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return (int)t[v].size() - (lower_bound(all(t[v]), qx) - t[v].begin());
    int m = l + r >> 1;
    return get(v << 1, l, m) + get(v << 1 | 1, m + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    set <int> st, rst;
    vector <ar <int, 2>> a(n);
    rst.insert(1);
    st.insert(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        b[i] = a[i][0];
        a[i][1] = i;
    }
    build();
    sort(all(a), greater<ar <int, 2>>());
    for (int j = 0; j < n; j++) {
        int i = a[j][1];
        int l = -*rst.lower_bound(-i) + 1, r = *st.lower_bound(i) - 1;
        ql = l, qr = i - 1, qx = 1 / k + 1;
        ans += get();
        ql = i + 1, qr = r;
        ans += get();
        if (r - i < i - l) {
            ql = l, qr = i - 1;
            for (int z = i + 1; z <= r; z++) {
                qx = b[i] / k / b[z] + 1;
                ans += get();
            }
        } else {
            ql = i + 1, qr = r;
            for (int z = l; z < i; z++) {
                qx = b[i] / k / b[z] + 1;
                ans += get();
            }
        }
        rst.insert(-i); st.insert(i);
    }
    cout << ans << '\n';
}