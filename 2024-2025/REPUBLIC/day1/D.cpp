#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define endl '\n'
#define print(a) for(auto x : a) cout << x << ' '; cout << endl;

struct SegTree {

    int size = 1;
    vector<int> sums;

    SegTree (int n){
        while(size < n)
            size <<= 1;
        sums.resize(size << 1);
        build(0, 0, size, n);
    }

    void build(int x, int lx, int rx, int n){
        if(rx - lx == 1){
            if(lx < n)
                sums[x] = 1;
            return;
        }
        int mid = (lx + rx) >> 1;
        build((x << 1) + 1, lx, mid, n);
        build((x << 1) + 2, mid, rx, n);
        sums[x] = sums[(x << 1) + 1] + sums[(x << 1) + 2];
    }

    int get(int k, int x, int lx, int rx, int s = 0){
        if(rx - lx == 1)
            return lx;
        int mid = (lx + rx) >> 1;
        if(sums[(x << 1) + 1] + s >= k)
            return get(k, (x << 1) + 1, lx, mid, s);
        else
            return get(k, (x << 1) + 2, mid, rx, s + sums[(x << 1) + 1]);
    }

    inline int get(int k){
        return get(k, 0, 0, size);
    }

    void set(int i, int p, int x, int lx, int rx){
        if(rx - lx == 1){
            sums[x] = p;
            return;
        }
        int mid = (lx + rx) >> 1;
        if(i < mid) set(i, p, (x << 1) + 1, lx, mid);
        else set(i, p, (x << 1) + 2, mid, rx);
        sums[x] = sums[(x << 1) + 1] + sums[(x << 1) + 2]; 
    }

    inline void set(int index, int p){
        set(index, p, 0, 0, size);
    }

};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    SegTree s(1e6 + 2);
	vector<int> fact(16);
	fact[0] = 1;
	for(int i = 1; i <= 15; i ++)
    	fact[i] = fact[i - 1] * i;
    for(int i = 0; i < q; i ++){
        
        int n, l, r;
        cin >> n >> l >> r;

        auto get = [&](int index, int ln, int sz) -> int {
            int ortiqcha = max(0ll, min(ln, sz - 15));
            int res = ortiqcha * (ortiqcha + 1) / 2;
            ln -= ortiqcha;
            if(ln <= 0)
                return res;
            sz = min(sz, 15ll);
            int f = fact[sz - 1];
            vector<int> r;
            for(int i = sz - 1; i >= sz - ln; i --){
                int ind = s.get(index / f + 1 + ortiqcha);
                r.push_back(ind);
                res += ind + 1;
                s.set(ind, 0);
                index %= f;
                f /= i;
            }
            for(int x : r)
                s.set(x, 1);
            return res;
        };

        int ans = (r / n - (l - 1) / n) * (n * (n + 1) / 2), index1 = (l - 1) / n, index2 = r / n;
        ans += get(index2, r - index2 * n, n) - get(index1, l - index1 * n - 1, n);
        cout << ans << endl;
    }
}