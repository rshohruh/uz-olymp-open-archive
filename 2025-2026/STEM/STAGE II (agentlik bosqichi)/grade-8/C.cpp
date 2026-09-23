#include "bits/stdc++.h"
using namespace std;
#define int int64_t

int32_t main() {
#ifdef khba
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int D; cin >> D;
    int o1, o2, o3; cin >> o3 >> o2 >> o1;
    int m1, m2, m3, m4; cin >> m4 >> m3 >> m2 >> m1;
    long double left = 0, right = 1e5;
    auto get = [&] (long double t) { return o3 * t * t * t + o2 * t * t + o1 * t + m4 * t * t * t * t + m2 * t * t + m1 * t + m3 * t * t * t; };
    for (int _ = 0; _ < 100; ++ _) {
        long double t = (left + right) / 2.;
        if (get(t) >= D) right = t;
        else left = t;
    }
    cout.precision(2);
    cout << fixed << (long double)(left);
}