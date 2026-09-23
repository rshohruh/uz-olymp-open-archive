#include <bits/stdc++.h>

using namespace std;

#define int long long
constexpr int mod = 1e9 + 7;

int32_t main() {
#ifdef JahonaliX
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, z = 1, x, y;
    cin >> n >> x >> y;
    char c;
    cin >> c;
    vector<vector<int>> a(n, vector<int>(n)), b = a;
    vector<vector<bool>> v(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = z++;
    if (x == n) reverse(a.begin(), a.end());
    if (y == n) for (int i = 0; i < n; ++i) reverse(a[i].begin(), a[i].end());
    vector<int> X{0, 1, 0, -1}, Y{1, 0, -1, 0};
    if (c == 'V') {
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) b[i][j] = a[j][i];
        a = b;
    }
    auto dfs = [&] (auto &&dfs, int i, int j, int dr) -> bool {
        if (i < 0 || j < 0 || i >= n || j >= n || v[i][j]) return true;
        v[i][j] = true;
        cout << a[i][j] << ' ';
        if (dfs(dfs, i + X[dr], j + Y[dr], dr)) dr++, dr %= 4, dfs(dfs, i + X[dr], j + Y[dr], dr);
        return false;
    };
    dfs(dfs, 0, 0, 0);
    return 0;
}