#include "photo.h"
#include <vector>
#include <set>
using namespace std;

vector<int> f;

void init(int k, int n, vector<int> a) {
    f.assign(n, 0);

    vector<multiset<int>> g(k);
    vector<int> o(k);
    int left = 0;

    for (int i = 1; i < n; ++i) {
        if (i % 2) {
            g[a[i - 1]].insert(a[i]);
            o[a[i]]++;
        } else {
            g[a[i]].insert(a[i - 1]);
            o[a[i - 1]]++;
        }

        vector<bool> v(k), u(k);

        auto dfs = [&](auto &&self, int j) -> bool {
            v[j] = true;
            u[j] = true;
            for (int l : g[j]) {
                if (v[l]) return false;
                if (u[l]) continue;
                if (!self(self, l)) return false;
            }
            v[j] = false;
            return true;
        };

        bool ok = false, finish = false;

        for (int j = 0; j < k; ++j) {
            if (u[j]) continue;
            ok = true;
            if (!dfs(dfs, j)) finish = true;
        }

        if (!ok || a[i - 1] == a[i]) finish = true;

        if (finish) {
            f[left] = i;

            if (left % 2 == 0) {
                g[a[left]].erase(g[a[left]].find(a[left + 1]));
                o[a[left + 1]]--;
            } else {
                g[a[left + 1]].erase(g[a[left + 1]].find(a[left]));
                o[a[left]]--;
            }

            left++;

            if (left != i) {
                if (i % 2) {
                    g[a[i - 1]].erase(g[a[i - 1]].find(a[i]));
                    o[a[i]]--;
                } else {
                    g[a[i]].erase(g[a[i]].find(a[i - 1]));
                    o[a[i - 1]]--;
                }
                i--;
            }
        }
    }

    while (left < n) f[left++] = n;
}

bool query(int l, int r) {
    return f[l] > r;
}
