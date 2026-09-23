#include <bits/stdc++.h>

using namespace std;

#define int long long
constexpr int mod = 1e9 + 7, inf = 1e17;

struct segment_tree {
    int n;
    vector<int> t;
    void build(vector<int> &a, int v = 1, int l = 0, int r = -1) {
        if (r < 0) r += n;
        if (l == r) t[v] = a[l];
        else {
            int m = (l + r) >> 1;
            build(a, v << 1, l, m);
            build(a, v << 1 | 1, m + 1, r);
            t[v] = min(t[v << 1], t[v << 1 | 1]);
        }
    } 
    segment_tree(vector<int> &a) { n = a.size(), t.assign(n << 2, inf), build(a); }
    int get(int L, int R, int v = 1, int l = 0, int r = -1) {
        if (r < 0) r += n;
        if (L <= l && r <= R) return t[v];
        int m = (l + r) >> 1;
        if (m >= R) return get(L, R, v << 1, l, m);
        if (m < L) return get(L, R, v << 1 | 1, m + 1, r);
        return min(get(L, R, v << 1, l, m), get(L, R, v << 1 | 1, m + 1, r));
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), l(m, n), r(m, -1);
    for (int &i : a) cin >> i, i--;
    for (int i = 0; i < n; ++i) l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);
    for (int i = 0; i < m; ++i) r[i] = -r[i];
    segment_tree mnl(l), mxr(r);
    vector<int> v, mxv, mnv;
    int mxx = a[0], mnn = a[0];
    for (int i = 1; i < n; ++i) {
        while (v.size() && mnl.get(mnn, mxx) < v.back()) {
            mxx = max(mxv.back(), mxx);
            mnn = min(mnv.back(), mnn);
            v.pop_back();
            mxv.pop_back();
            mnv.pop_back();
        }
        if (-mxr.get(mnn, mxx) >= i) mxx = max(mxx, a[i]), mnn = min(mnn, a[i]);
        else {
            v.emplace_back(i);
            mxv.emplace_back(mxx);
            mnv.emplace_back(mnn);
            mxx = mnn = a[i];
        }
    }
    v.emplace_back(n);
    cout << v.size() << '\n';
    for (int i : v) cout << i << ' ';
    return 0;
}