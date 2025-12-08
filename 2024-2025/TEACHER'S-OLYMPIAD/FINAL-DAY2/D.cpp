// author: rshohruh

#pragma GCC optimize("Ofast")
#include "iostream"
#include "cassert"

#ifdef LOCAL
    #include "debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

#define all(a) (a).begin(), (a).end()
#define int long long

// #define with_testcases
signed main(){
    const int mod = 1e9 + 7;
    int n, k, q; cin >> n >> k >> q;
    assert(n >= 1 && n <= mod - 7);
    assert(k > 1 && k <= mod - 7);
    assert(q >= 1 && q <= 100000);
  
    auto cost = [&](int x) {
        int c = 1;
        int ans = 0;
        while(x) {
            if(x & 1) (ans += c) %= mod;
            x /= 2;
            (c *= k) %= mod;
        }
        return ans;
    };
    while(q--) {
        int x; cin >> x;
        assert(1 <= x && x <= n);
        cout << cost(n-x+1) << '\n';
    }
}