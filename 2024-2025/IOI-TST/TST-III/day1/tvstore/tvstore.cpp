#include "tvstore.h"
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

using ll = long long;

struct Fenwick {
    vector<pair<ll, ll>> pref, suff;
    ll offs, n;

    Fenwick(ll N) {
        pref.assign(N + 21, {-1, -1});
        suff.assign(N + 21, {-1, -1});
        offs = 10;
        n = N + 20;
    }

    void add(ll idx, ll val, ll x) {
        idx += offs;
        for (ll i = idx; i <= n; i += (i & -i))
            pref[i] = max(pref[i], {val, x});
        for (ll i = idx; i; i -= (i & -i))
            suff[i] = max(suff[i], {val, x});
    }

    pair<ll, ll> get_pref(ll i) {
        i += offs;
        pair<ll, ll> res = {-1, -1};
        for (; i; i -= (i & -i)) res = max(res, pref[i]);
        return res;
    }

    pair<ll, ll> get_suff(ll i) {
        i += offs;
        pair<ll, ll> res = {-1, -1};
        for (; i <= n; i += (i & -i)) res = max(res, suff[i]);
        return res;
    }
};

vector<int> best_tv(int n, vector<int> w, vector<int> h, vector<int> c,
                    int q, vector<int> x, vector<int> y, vector<int> b) {

    vector<int> res(q, -1);
    vector<array<ll,4>> tv(n);
    vector<array<ll,3>> qs(q);
    vector<array<ll,2>> all;

    for (int i = 0; i < n; ++i) {
        tv[i] = {w[i], h[i], c[i], i};
        all.push_back({w[i], h[i]});
    }

    for (int i = 0; i < q; ++i)
        all.push_back({x[i], y[i]});

    sort(all.begin(), all.end(), [](auto &a, auto &b){
        return a[0] * b[1] < b[0] * a[1];
    });
    all.erase(unique(all.begin(), all.end()), all.end());

    auto get_index = [&](ll cw, ll ch){
        array<ll,2> cur = {cw, ch};
        return lower_bound(all.begin(), all.end(), cur, [](auto &a, auto &b){
            return a[0] * b[1] < b[0] * a[1];
        }) - all.begin();
    };

    vector<vector<pair<int,int>>> events(1000001);

    for (int i = 0; i < n; ++i) {
        tv[i][3] = get_index(tv[i][0], tv[i][1]);
        events[tv[i][2]].push_back({0, i});
    }

    for (int i = 0; i < q; ++i) {
        qs[i] = {x[i], y[i], b[i]};
        events[b[i]].push_back({1, i});
    }

    Fenwick fw(all.size()), fh(all.size());

    for (int cost = 1; cost <= 1000000; ++cost) {

        for (auto [type, id] : events[cost]) {
            if (type == 0) {
                fw.add(tv[id][3], tv[id][0], id);
                fh.add(tv[id][3], tv[id][1], id);
            }
        }

        for (auto [type, id] : events[cost]) {
            if (type == 1) {
                ll cw = qs[id][0], ch = qs[id][1];
                ll g = gcd(cw, ch);
                cw /= g; ch /= g;

                ll idx = get_index(cw, ch);

                pair<ll,ll> best = {-1, -1};
                auto A = fh.get_suff(idx);
                auto B = fw.get_pref(idx);

                if (A.first != -1) {
                    ll t = A.first / ch;
                    if (t) best = max(best, {t * cw * t * ch, A.second});
                }

                if (B.first != -1) {
                    ll t = B.first / cw;
                    if (t) best = max(best, {t * cw * t * ch, B.second});
                }

                res[id] = best.second;
            }
        }
    }

    return res;
}
