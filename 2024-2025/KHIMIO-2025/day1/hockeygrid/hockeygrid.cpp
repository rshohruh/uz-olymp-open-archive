#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void t_main() {
    int n, q;
    cin >> n >> q;

    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    int H = 0;
    while ((1 << H) <= 2 * n - 2) ++H;

    vector up(n, vector(n, vector(H, make_pair(-1, -1))));
    vector down(n, vector(n, vector(H, make_pair(-1, -1))));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == n - 1 && j == n - 1) {
                up[i][j] = down[i][j] =
                    vector<pair<int, int>>(H, make_pair(n, n));
            } else {
                int I = -1, J = -1;

                if (g[i][j] == 'v' || g[i][j] == 'o') {
                    if (i + 1 != n && up[i + 1][j][0].first != -1) {
                        I = i + 1;
                        J = j;
                    }
                }
                if (g[i][j] == '>' || g[i][j] == 'o') {
                    if (j + 1 != n && up[i][j + 1][0].first != -1) {
                        I = i;
                        J = j + 1;
                    }
                }

                if (I != -1) {
                    up[i][j][0] = make_pair(I, J);
                    for (int h = 1; h < H; ++h) {
                        auto [u, v] = up[i][j][h - 1];
                        if (u == n) {
                            --u;
                            --v;
                        }
                        up[i][j][h] = up[u][v][h - 1];
                    }

                    if (g[i][j] == 'o' && i + 1 != n &&
                        up[i + 1][j][0].first != -1) {
                        I = i + 1;
                        J = j;
                    }
                    down[i][j][0] = make_pair(I, J);
                    for (int h = 1; h < H; ++h) {
                        auto [u, v] = down[i][j][h - 1];
                        if (u == n) {
                            --u;
                            --v;
                        }
                        down[i][j][h] = down[u][v][h - 1];
                    }
                }
            }
        }
    }

    auto can = [&](int x, int y, int X, int Y) {
        if (y > Y) return false;
        if (x > X) return false;

        int upy = y, downy = y;
        int xx = x;

        for (int h = H - 1; h >= 0; --h) {
            if (up[xx][upy][h].first <= X)
                tie(xx, upy) = up[xx][upy][h];
        }

        xx = x;
        if (x != X) {
            for (int h = H - 1; h >= 0; --h) {
                if (down[xx][downy][h].first < X)
                    tie(xx, downy) = down[xx][downy][h];
            }
            tie(xx, downy) = down[xx][downy][0];
        }

        return downy <= Y && Y <= upy;
    };

    vector<pair<int, int>> a;

    auto check = [&]() {
        sort(a.begin(), a.end());
        for (int i = 1; i < (int)a.size(); ++i) {
            if (!can(a[i - 1].first, a[i - 1].second,
                     a[i].first, a[i].second))
                return false;
        }
        return true;
    };

    while (q-- > 0) {
        int k;
        cin >> k;
        a.resize(k);
        for (auto &x : a) {
            cin >> x.first >> x.second;
            --x.first;
            --x.second;
        }
        cout << (check() ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T-- > 0) t_main();
    return 0;
}
