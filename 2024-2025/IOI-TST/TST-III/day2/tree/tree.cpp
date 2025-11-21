#include "tree.h"
#include <vector>
#include <tuple>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;

struct SegTree {
    vector<int> t;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        t.assign(2 * size, 0);
    }

    void update(int p, int v) {
        p += size;
        t[p] = v;
        for (; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }

    int kth(int k) {
        int x = 1;
        while (x < size) {
            if (t[x << 1] > k) x <<= 1;
            else {
                k -= t[x << 1];
                x = x << 1 | 1;
            }
        }
        return x - size;
    }

    int query(int l, int r) {
        if (l > r) return 0;
        int res = 0;
        for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};

vector<ll> answer(int n, int root, vector<int> p, int q, vector<ll> k) {
    vector<ll> res(q);
    vector<vector<int>> children(n);
    vector<int> sub_size(n, 1), heavy(n + 1);

    for (int i = 0; i < n; ++i)
        if (i != root)
            children[p[i]].push_back(i);

    SegTree sg, sg2;
    sg.init(n);
    sg2.init(n);

    vector<vector<pair<ll,int>>> queries(n);
    vector<vector<tuple<int,int,int>>> qq(n);
    vector<vector<int>> vec(n);

    for (int i = 0; i < q; ++i) {
        int u = k[i] / n;
        queries[u].push_back({k[i] % n, i});
        res[i] = (ll)u * n * n;
    }

    auto dfs = [&](auto self, int u) -> void {
        for (int v : children[u]) {
            self(self, v);
            sub_size[u] += sub_size[v];
        }
        sort(children[u].begin(), children[u].end(),
             [&](int a, int b){ return sub_size[a] < sub_size[b]; });
        heavy[u] = children[u].empty() ? u : heavy[children[u].back()];
    };
    dfs(dfs, root);
    heavy[n] = n;

    vector<int> pos(n), ord(n);

    auto dfs2 = [&](auto self, int u, int h, bool clear) -> void {
        ord[h] = u; pos[u] = h;
        sg.update(u, sub_size[u]);

        for (auto [x, idx] : queries[u]) {
            int v = sg.kth(x);
            res[idx] += (ll)v * n;
            if (u != v)
                qq[v].emplace_back(ord[pos[v] + 1], x - sg.query(0, v - 1), idx);
            else
                qq[v].emplace_back(n, x - sg.query(0, v - 1), idx);
        }

        for (int v : children[u]) {
            sg.update(u, sub_size[u] - sub_size[v]);
            self(self, v, h + 1, v != children[u].back());
        }
        sg.update(u, 0);

        bool exist = false;
        for (auto [v,x,i] : qq[u]) exist |= heavy[v] == heavy[u];
        if (exist) {
            vector<int> all = {u};
            for (int v : children[u]) {
                if (heavy[u] == heavy[v]) continue;
                for (int x : vec[heavy[v]]) all.push_back(x);
            }
            sort(all.begin(), all.end());
            for (auto [v,x,i] : qq[u])
                if (heavy[v] == heavy[u]) res[i] += all[x];
        }

        for (int v : children[u]) {
            if (heavy[u] == heavy[v]) continue;
            for (int x : vec[heavy[v]]) {
                vec[heavy[u]].push_back(x);
                sg2.update(x, 1);
            }
        }

        sg2.update(u, 1);
        vec[heavy[u]].push_back(u);

        sort(qq[u].begin(), qq[u].end());
        for (int i = 0; i < (int)qq[u].size(); ++i) {
            auto [v,x,idx] = qq[u][i];
            if (heavy[v] == heavy[u]) continue;
            if (i == 0 || v != get<0>(qq[u][i - 1])) {
                if (v < n) for (int y : vec[heavy[v]]) sg2.update(y, 0);
            }
            res[idx] += sg2.kth(x);
            if (i + 1 == (int)qq[u].size() || v != get<0>(qq[u][i + 1])) {
                if (v < n) for (int y : vec[heavy[v]]) sg2.update(y, 1);
            }
        }

        if (clear)
            for (int x : vec[heavy[u]]) sg2.update(x, 0);

        for (int v : children[u])
            if (heavy[u] != heavy[v])
                vec[heavy[v]].clear();
    };

    dfs2(dfs2, root, 0, false);
    return res;
}
