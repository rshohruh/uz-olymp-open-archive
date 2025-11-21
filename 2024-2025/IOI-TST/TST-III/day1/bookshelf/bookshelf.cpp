#include "bookshelf.h"
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

static const int MAXN = 105;
set<int> edges[MAXN];
int ed[MAXN][MAXN];
int usedArr[MAXN], vis[MAXN], par[MAXN];
vector<int> idpos[MAXN][MAXN];

int sort_books(int n, int m, int T, vector<vector<int>> a) {
    vector<bool> row_in(n), col_in(m);
    vector<bool> row_dist(n), col_dist(m);

    bool already = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] != i * m + j)
                already = false;

    if (already) return 0;

    for (int i = 0; i < n; ++i) {
        row_in[i] = true;
        row_dist[i] = true;
        vector<bool> used(m, false);

        for (int j = 0; j < m; ++j) {
            int x = a[i][j] / m;
            int y = a[i][j] % m;

            if (x != i) row_in[i] = false;
            if (used[y]) row_dist[i] = false;
            used[y] = true;
        }
    }

    for (int j = 0; j < m; ++j) {
        col_in[j] = true;
        col_dist[j] = true;
        vector<bool> used(n, false);

        for (int i = 0; i < n; ++i) {
            int x = a[i][j] / m;
            int y = a[i][j] % m;

            if (y != j) col_in[j] = false;
            if (used[x]) col_dist[j] = false;
            used[x] = true;
        }
    }

    auto all_true = [&](vector<bool>& v){
        for (bool x : v) if (!x) return false;
        return true;
    };

    auto do_row = [&](){
        for (int i = 0; i < n; ++i)
            sort(a[i].begin(), a[i].end());
    };

    auto do_col = [&](){
        for (int j = 0; j < m; ++j) {
            vector<int> col(n);
            for (int i = 0; i < n; ++i) col[i] = a[i][j];
            sort(col.begin(), col.end());
            for (int i = 0; i < n; ++i) a[i][j] = col[i];
        }
    };

    auto do_row2 = [&](){
        for (int i = 0; i < n; ++i)
            sort(a[i].begin(), a[i].end(), [&](int x, int y){
                return (x % m) < (y % m);
            });
    };

    if (all_true(row_in)) {
        do_row();
        rearrange_row(a);
        return 1;
    }

    if (all_true(col_in)) {
        do_col();
        rearrange_column(a);
        return 1;
    }

    if (all_true(row_dist)) {
        do_row2();
        rearrange_row(a);
        do_col();
        rearrange_column(a);
        return 2;
    }

    if (all_true(col_dist)) {
        do_col();
        rearrange_column(a);
        do_row();
        rearrange_row(a);
        return 2;
    }

    vector<vector<int>> b(n, vector<int>(m)), c(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
       edges[i].clear();
        for (int j = 0; j < n; ++j) {
            ed[i][j] = 0;
            idpos[i][j].clear();
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int x = a[i][j] / m;
            ed[i][x]++;
            edges[i].insert(x);
            idpos[i][x].push_back(j);
        }

    for (int j = 0; j < m; ++j) {
        fill(usedArr, usedArr + MAXN, -1);
        fill(par, par + MAXN, -1);

        function<bool(int)> dfs = [&](int u){
            vis[u] = 1;
            for (int x : edges[u]) {
                if (par[x] != -1 && vis[par[x]]) continue;
                if (par[x] == -1 || dfs(par[x])) {
                    usedArr[u] = x;
                    par[x] = u;
                    return true;
                }
            }
            return false;
        };

        for (int i = 0; i < n; ++i) {
            if (usedArr[i] != -1) continue;
            fill(vis, vis + MAXN, 0);
            dfs(i);
        }

        for (int i = 0; i < n; ++i) {
            int x = usedArr[i];
            b[i][j] = a[i][idpos[i][x].back()];
            idpos[i][x].pop_back();
            ed[i][x]--;
            if (!ed[i][x]) edges[i].erase(x);
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    for (int j = 0; j < m; ++j) {
        sort(p.begin(), p.end(), [&](int i, int k){
            return b[i][j] < b[k][j];
        });

        for (int i = 0; i < n; ++i)
            c[i][j] = b[p[i]][j];
    }

    a = c;
    do_row();

    rearrange_row(b);
    rearrange_column(c);
    rearrange_row(a);

    return 3;
}
