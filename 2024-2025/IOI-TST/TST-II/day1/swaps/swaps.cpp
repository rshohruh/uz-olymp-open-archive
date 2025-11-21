#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n), q(n), a(n), posP(n), posQ(n);
    for (int &x : p) cin >> x;
    for (int &x : q) cin >> x;
    for (int &x : a) cin >> x;

    vector<bool> used(n, false);

    for (int i = 0; i < n; ++i)
        if (p[i] == q[i])
            used[i] = true;

    for (int i = 0; i < n; ++i) {
        posP[p[i]] = i;
        posQ[q[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i] && a[i] < 1) {
            cout << "NO\n";
            return 0;
        }
    }

    vector<pair<int,int>> ops;
    bool phase = true;

    auto dfs = [&](auto self, int i) -> void {
        used[i] = true;

        if (a[i] > 1 && !used[posP[q[i]]]) {
            self(self, posP[q[i]]);
        }

        if (q[i] == p[i] || (phase && a[posQ[p[i]]] < 2)) return;

        int j = posQ[p[i]];

        ops.emplace_back(i, j);
        a[i]--;
        a[j]--;

        swap(posQ[q[i]], posQ[p[i]]);
        swap(q[i], q[j]);

        used[i] = false;
    };

    for (int i = 0; i < n; ++i) {
        if (p[i] != q[i] && a[i] > 1)
            dfs(dfs, i);
    }

    phase = false;

    for (int i = 0; i < n; ++i) {
        if (p[i] != q[i])
            dfs(dfs, i);
    }

    for (int i = 0; i < n; ++i) {
        if (p[i] != q[i] || a[i] < 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    cout << ops.size() << "\n";
    for (auto [x, y] : ops)
        cout << x << " " << y << "\n";

    return 0;
}
