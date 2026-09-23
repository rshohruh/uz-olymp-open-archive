#include "bits/stdc++.h"
using namespace std;
#define int int64_t

int32_t main()
{
#ifdef khba
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(4));
    map<vector<int>, int> cnt;
    for (auto &v : a) {
        for (int &i : v)
            cin >> i;
        cnt[v]++;
    }
    int ans = 0;
    vector<vector<int>> triple;
    for (int x : {1, 2, 3})
        for (int y : {1, 2, 3})
            for (int z : {1, 2, 3})
                for (int k : {1, 2, 3})
                    triple.push_back(vector<int>({x, y, z, k}));
    for (auto &f : triple)
    {
        for (auto &s : triple)
        {
            vector <int> th(4);
            for (int i = 0; i < 4; ++i) if (f[i] == s[i]) th[i] = s[i]; else th[i] = s[i] ^ f[i];
            if (cnt.count(f) and cnt.count(s) and cnt.count(th)) {
                if (f <= s and s <= th) {
                    // for (auto &i : f) cout << i << ' '; cout << '\n';
                    // for (auto &i : s) cout << i << ' '; cout << '\n';
                    // for (auto &i : th) cout << i << ' '; cout << '\n'; 
                    // cout << cnt[f] << ' ' << cnt[s] << ' ' << cnt[th] << endl; cout << '\n';
                    if (f == th) ans += cnt[f] * (cnt[f] - 1) * (cnt[f] - 2) / 6;
                    else if (f == s) ans += cnt[f] * (cnt[f] - 1) / 2 * cnt[th];
                    else if (s == th) ans += cnt[th] * (cnt[th] - 1) / 2 * cnt[f];
                    else ans += cnt[f] * cnt[s] * cnt[th];            
                } 
            }
        }
    }
    cout << ans << endl;
    // cout << ans / 6;
    return 0;
}