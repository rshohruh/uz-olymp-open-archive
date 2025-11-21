#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

struct Point {
    ll x, y;
    int id;
    bool operator<(const Point &o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

struct LineContainer {
    vector<Point> v;

    ll cross(const Point &a, const Point &b, const Point &c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    void build() {
        sort(v.begin(), v.end());
        vector<Point> hull;
        for (auto &p : v) {
            while (hull.size() > 1 &&
                   cross(hull[hull.size()-2], hull.back(), p) <= 0)
                hull.pop_back();
            hull.push_back(p);
        }
        v = hull;
    }

    void add(ll ps, ll ns, int idx) {
        v.push_back({ps, ns, -idx});
    }

    pair<ll,int> eval(const Point &p1, const Point &p2) {
        return {p1.x * p2.x + p1.y * p2.y, p1.id};
    }

    pair<ll,int> query(ll A, ll B) {
        Point p = {A, -B, 0};
        pair<ll,int> best = {-(1LL<<60), 0};

        int l = 0, r = (int)v.size() - 1;
        while (r - l > 2) {
            int m1 = (l*2 + r) / 3;
            int m2 = (l + r*2) / 3;
            if (eval(v[m1], p) >= eval(v[m2], p)) r = m2;
            else l = m1;
        }

        for (int i = l; i <= r; ++i)
            best = max(best, eval(v[i], p));

        best.second = -best.second;
        return best;
    }
};

struct Fenwick {
    vector<ll> t;

    void build(const vector<int> &a) {
        int n = a.size();
        t.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            t[i] += a[i];
            int j = i | (i + 1);
            if (j < n) t[j] += t[i];
        }
    }

    void update(int i, ll delta) {
        for (; i < (int)t.size(); i |= i + 1)
            t[i] += delta;
    }

    ll sum(int i) {
        ll s = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            s += t[i];
        return s;
    }

    ll range(int l, int r) {
        return sum(r) - (l ? sum(l-1) : 0);
    }
};

struct Solver {
    int n;
    vector<int> a, b;
    Fenwick fa, fb;

    int block_size = 250;
    vector<LineContainer> blocks;
    vector<int> L, R;
    vector<ll> sumA, sumB;

    Solver(int n): n(n) {
        a.assign(n, 0);
        b.assign(n, 0);

        int cnt = (n + block_size - 1) / block_size;
        blocks.resize(cnt);
        L.resize(cnt);
        R.resize(cnt);
        sumA.resize(cnt);
        sumB.resize(cnt);

        for (int i = 0; i < cnt; ++i) {
            L[i] = i * block_size;
            R[i] = min(n-1, (i+1) * block_size - 1);
        }
    }

    void rebuildBlock(int id) {
        blocks[id].v.clear();
        sumA[id] = sumB[id] = 0;

        ll A = 0, B = 0;
        for (int i = L[id]; i <= R[id]; ++i) {
            A += a[i];
            B += b[i];
            sumA[id] += a[i];
            sumB[id] += b[i];
            blocks[id].add(A, B, i);
        }
        blocks[id].build();
    }

    void build(const vector<int> &aa, const vector<int> &bb) {
        a = aa;
        b = bb;
        fa.build(a);
        fb.build(b);
        for (int i = 0; i < (int)blocks.size(); ++i)
            rebuildBlock(i);
    }

    void update(int type, int idx, int val) {
        int block = idx / block_size;

        if (type == 1) {
            fa.update(idx, val - a[idx]);
            a[idx] = val;
        } else {
            fb.update(idx, val - b[idx]);
            b[idx] = val;
        }

        rebuildBlock(block);
    }

    ll query(int l, int r) {
        ll A = fa.range(l, r);
        ll B = fb.range(l, r);

        ll res = -(1LL<<60);
        ll sa = 0, sb = 0;

        int bl = l / block_size;
        int br = r / block_size;

        if (bl == br) {
            for (int i = l; i <= r; ++i) {
                sa += a[i];
                sb += b[i];
                res = max(res, sa * B - sb * A);
            }
            return res;
        }

        for (int i = l; i <= R[bl]; ++i) {
            sa += a[i];
            sb += b[i];
            res = max(res, sa * B - sb * A);
        }

        for (int i = bl + 1; i < br; ++i) {
            auto g = blocks[i].query(B, A);
            res = max(res, sa * B - sb * A + g.first);
            sa += sumA[i];
            sb += sumB[i];
        }

        for (int i = L[br]; i <= r; ++i) {
            sa += a[i];
            sb += b[i];
            res = max(res, sa * B - sb * A);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    Solver sol(n);
    sol.build(a, b);

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t <= 2) {
            sol.update(t, x-1, y);
        } else {
            cout << sol.query(x-1, y-1) << "\n";
        }
    }
    return 0;
}
