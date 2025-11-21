#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
struct segtree
{
    vector<int> t;
    vector<int> L;
    vector<int> R;
 
    int new_node(int prev) {
        t.push_back(-1);
        L.push_back(-1);
        R.push_back(-1);
        if (prev != -1) {
            L.back() = L[prev];
            R.back() = R[prev];
        }
        return t.size() - 1;
    }
 
    int build(int l, int r) {
        int x = new_node(-1);
        if (l == r) {
            return x;
        }
        int m = (l + r) / 2;
        L[x] = build(l, m);
        R[x] = build(m + 1, r);
        return x;
    }
 
    segtree(int n) {
        build(0, n - 1);
    }
 
 
    int upd(int x, int l, int r, int i, int y) {
        assert (x != -1);
        int new_x = new_node(x);
        if (l == r) {
            t[new_x] = y;
            return new_x;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            L[new_x] = upd(L[x], l, m, i, y);
        } else {
            R[new_x] = upd(R[x], m + 1, r, i, y);
        }
        t[new_x] = max(t[L[new_x]], t[R[new_x]]);
        return new_x;
    }
 
    int get(int x, int l, int r, int tl, int tr) {
        if (tl > tr) {
            return -1;
        } else if (l == tl && r == tr) {
            return t[x];
        }
        int m = (l + r) / 2;
        return max(get(L[x], l, m, tl, min(m, tr)), get(R[x], m + 1, r, max(m + 1, tl), tr));
    }
};
 
struct DSU {
    int G;
    vector<int> p;
    vector<int> d;
    vector<vector<int>> v;
     
    int tim;
    vector<int> tin;
    vector<int> tout;
    vector<vector<int>> f;
 
    DSU(int n) : p(n * 2), d(n * 2), v(n * 2), tin(n * 2), tout(n * 2), f(n * 2, vector<int> (19, 0)) {
        G = n;
        tim = 0;
        for (int i = 0; i < 2 * n; i++) {
            p[i] = i;
        }
    }
 
    int get(int x) {
        return p[x] == x ? x : p[x] = get(p[x]);
    }
 
    int make(int x, int y, int w) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return -1;
        }
        p[x] = G;
        p[y] = G;
        v[G] = {x, y};
        d[G] = w;
        return G++;
    }
 
    void dfs(int x, int p) {
        tin[x] = tim;
        tim += v[x].empty();
 
        f[x][0] = p;
        for (int i = 1; i < 19; i++) {
            f[x][i] = f[f[x][i - 1]][i - 1];
        }
 
        for (int y: v[x]) {
            dfs(y, x);
        }
 
        tout[x] = tim - 1;
    }
 
    pair<int, int> jump(int x, int w) {
        for (int i = 18; i >= 0; i--) {
            if (d[f[x][i]] <= w) {
                x = f[x][i];
            }
        }
        return {tin[x], tout[x]};
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> e1(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x -= 1;
        y -= 1;
        e1[i] = {x, y, w};
    }
    vector<vector<int>> e2(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x -= 1;
        y -= 1;
        e2[i] = {x, y, w};
    }
 
    vector<pair<int, int>> qu(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        qu[i] = {x, y};
    }
 
    sort(e1.begin(), e1.end(), [](const vector<int> &x, const vector<int> &y) {
        return x[2] < y[2];
    });
    sort(e2.begin(), e2.end(), [](const vector<int> &x, const vector<int> &y) {
        return x[2] < y[2];
    });
 
    DSU T1(n);
    DSU T2(n);
    int r1 = -1, r2 = -1;
    for (int i = 0; i < n - 1; i++) {
        r1 = T1.make(e1[i][0], e1[i][1], e1[i][2]);
        r2 = T2.make(e2[i][0], e2[i][1], e2[i][2]);
    }
    assert (r1 == 2 * n - 2);
    assert (r2 == 2 * n - 2);
 
    T1.dfs(r1, r1);
    T2.dfs(r2, r2);
 
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[T1.tin[i]] = T2.tin[i];
    }
 
    segtree T(n);
 
 
    vector<int> versions(n);
    int cur_root = 0;
    for (int i = 0; i < n; i++) {
        cur_root = T.upd(cur_root, 0, n - 1, a[i], i);
        versions[i] = cur_root;
    }

    for (int i = 0; i < q; i++) {
        int x = qu[i].fi;
        int y = qu[i].se;
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
             
            auto A = T1.jump(x, m);
            auto B = T2.jump(y, m);
            if (T.get(versions[A.se], 0, n - 1, B.fi, B.se) >= A.fi) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << l << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}