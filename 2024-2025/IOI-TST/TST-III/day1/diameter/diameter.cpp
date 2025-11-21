#include "diameter.h"
#include <vector>
#include <array>
#include <algorithm>
#include <functional>
using namespace std;

struct Node {
    int lef = -1000000000, rig = 0, ans = 0;
};

struct SegTree {
    vector<Node> t;
    Node emptyNode;
    int n;

    void init(int sz) {
        n = sz;
        t.assign((n + 5) << 2, emptyNode);
    }

    Node merge(const Node &a, const Node &b) {
        Node res;
        res.ans = max(max(a.ans, b.ans), a.lef + b.rig);
        res.lef = max(a.lef, b.lef);
        res.rig = max(a.rig, b.rig);
        return res;
    }

    int qi, ql, qr;
    Node qx;

    void update(int v, int l, int r) {
        if (l == r) {
            t[v] = qx;
            return;
        }
        int m = (l + r) >> 1;
        if (qi <= m) update(v << 1, l, m);
        else update(v << 1 | 1, m + 1, r);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void update(int i, Node x) {
        qi = i; qx = x;
        update(1, 0, n);
    }

    Node get(int v, int l, int r) {
        if (ql <= l && r <= qr) return t[v];
        if (qr < l || r < ql) return emptyNode;
        int m = (l + r) >> 1;
        return merge(get(v << 1, l, m), get(v << 1 | 1, m + 1, r));
    }

    int query(int l, int r) {
        ql = l; qr = r;
        return get(1, 0, n).ans;
    }
};

vector<int> find_diameters(int n, vector<int> u, vector<int> v) {
    vector<int> res(n, -1);

    vector<vector<array<int,2>>> g(n);
    for (int i = 0; i < n; ++i) {
        g[u[i]].push_back({v[i], i});
        g[v[i]].push_back({u[i], i});
    }

    vector<int> tin(n), low(n), vis(n), comp(n), brdge(n);
    int timer = 0;

    function<void(int)> mark = [&](int x){
        comp[x] = 1;
        for (auto y : g[x])
            if (!comp[y[0]])
                mark(y[0]);
    };

    function<void(int,int)> dfsb = [&](int x, int p){
        vis[x] = 1;
        tin[x] = low[x] = ++timer;
        for (auto e : g[x]) {
            int y = e[0], id = e[1];
            if (y == p) continue;
            brdge[id] = 1;
            if (!vis[y]) {
                dfsb(y, x);
                if (low[y] <= tin[x]) brdge[id] = 0;
                low[x] = min(low[x], low[y]);
            } else {
                low[x] = min(low[x], tin[y]);
            }
        }
    };

    int farNode, bestDist;

    function<void(int,int,int)> dfsdiam = [&](int x, int p, int d){
        if (d > bestDist) {
            bestDist = d;
            farNode = x;
        }
        for (auto e : g[x])
            if (e[0] != p && brdge[e[1]])
                dfsdiam(e[0], x, d + 1);
    };

    mark(0);
    for (int i = 0; i < n; ++i)
        if (!comp[i]) return res;

    dfsb(0, -1);

    int loopEdge = 0;
    for (int i = 0; i < n; ++i)
        if (!brdge[i]) loopEdge = i;

    vector<int> cycle, which;
    int prev = u[loopEdge], cur = u[loopEdge], ed = loopEdge;
    cycle.push_back(cur);
    which.push_back(0);
    cur = v[loopEdge];

    while (cur != cycle[0]) {
        cycle.push_back(cur);
        which.push_back(ed);
        for (auto e : g[cur]) {
            if (e[0] != prev && !brdge[e[1]]) {
                prev = cur;
                cur = e[0];
                ed = e[1];
                break;
            }
        }
    }
    which[0] = ed;

    int m = cycle.size();
    SegTree st;
    st.init(2 * m);

    int diam = 0;
    for (int i = 0; i < m; ++i) {
        bestDist = -1;
        dfsdiam(cycle[i], -1, 0);
        st.update(i, {bestDist - i, bestDist + i, 0});
        st.update(i + m, {bestDist - i - m, bestDist + i + m, 0});

        int start = farNode;
        bestDist = -1;
        dfsdiam(start, -1, 0);
        diam = max(diam, bestDist);
    }

    for (int i = 0; i < m; ++i)
        res[which[i]] = max(diam, st.query(i, i + m - 1));

    return res;
}
