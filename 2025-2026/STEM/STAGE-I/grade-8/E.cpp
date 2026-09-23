#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define line '\n'

#define big __int128_t

void solve() {
    int n; cin >> n; int q; cin >> q;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    vector<int> inv(n+1);
    for (int i = 0; i < n; ++i) inv[v[i]] = i;
    stack<int> st;
    vector<int> l(n,-1), r(n,n);
    for (int i = 0; i < n; ++i) {
        while (st.size() and v[st.top()] > v[i]) st.pop();
        if (st.size()) l[i] = st.top();
        st.push(i);
    }
    while (st.size()) st.pop();
    for (int i = n - 1; ~i; --i) {
        while (st.size() and v[st.top()] > v[i]) st.pop();
        if (st.size()) r[i] = st.top();
        st.push(i);
    }
    while (q--) {
        int m, k; cin >> m >> k;
        int idx = inv[k];
        int left = idx - l[idx], right = r[idx] - idx;
        int len = left + right - 1;
        if (len < m or m == 1) cout << 1 << line;
        else cout << len << line;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t = 1;
    while (t--) {
        solve();
        cout << line;
    }
}