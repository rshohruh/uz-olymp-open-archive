#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll modpow(ll a, ll e) {
    ll r = 1;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    int m;
    cin >> n >> m;
    vector<long long> L(m), R(m);
    vector<int> maskLetter(m, 0); 

    for(int i = 0; i < m; ++i){
        string S;
        cin >> L[i] >> R[i] >> S;
        int mask = 0;
        for(char c : S){
            mask |= 1 << (c - 'a');
        }
        maskLetter[i] = mask;
    }

    int totalMasks = 1 << m;
    ll ans = 0;

    for(int mask = 0; mask < totalMasks; ++mask){
        vector<int> idx;
        idx.reserve(20);
        for(int i = 0; i < m; ++i) if (mask & (1<<i)) idx.push_back(i);

        vector<long long> pts;
        pts.reserve(2 + idx.size()*2);
        pts.push_back(1);
        pts.push_back(n+1);
        for(int id : idx){
            long long a = L[id];
            long long b = R[id] + 1; 
            if (a < 1) a = 1;
            if (a > n+1) a = n+1;
            if (b < 1) b = 1;
            if (b > n+1) b = n+1;
            pts.push_back(a);
            pts.push_back(b);
        }
        sort(pts.begin(), pts.end());
        pts.erase(unique(pts.begin(), pts.end()), pts.end());

        ll ways = 1;
        bool zero = false;
        for(size_t j = 0; j + 1 < pts.size(); ++j){
            long long start = pts[j];
            long long endpos = pts[j+1] - 1; // inclusive
            if (start > endpos) continue;
            long long len = endpos - start + 1;

            int unionMask = 0;
            for(int id : idx){
                if (L[id] <= start && R[id] >= start){
                    unionMask |= maskLetter[id];
                }
            }
            int cntUnion = __builtin_popcount((unsigned)unionMask);
            int allowed = 26 - cntUnion;
            if (allowed == 0){
                zero = true;
                break;
            }
            ways = ways * modpow(allowed, len) % MOD;
        }
        if (zero) ways = 0;

        if (__builtin_popcount(mask) & 1) ans = (ans - ways + MOD) % MOD;
        else ans = (ans + ways) % MOD;
    }
    cout << ans;
    return 0;
}