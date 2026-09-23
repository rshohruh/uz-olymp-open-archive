#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define line '\n'

#define big __int128_t

void solve() {
    int type; cin >> type;
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        char c; cin >> c;
        v[i][j] = (c == '+');
    }
    auto add = [&](string s, big x)->string{
        string t;
        while (x) {
            t += char(x%10+'0');
            x/=10;
        }
        reverse(all(t));
        while (t.size() < s.size()) t = '0' + t;
        int add = 0;
        for (int i = s.size() - 1; ~i; --i) {
            int a = s[i] - '0', b = t[i] - '0';
            s[i] = (a + b + add) % 10 + '0';
            add = (a + b + add) / 10;
        }
        if (add) s = char(add+'0') + s;
        return s;
    };
    if (type == 1) {
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < m; ++j) {
                if (v[i][j]) cur++;
                else {
                    p[i] += cur * (cur - 1) / 2;
                    cur = 0;
                }
            }
            if (cur) p[i] += cur * (cur - 1) / 2;
        }
        string ans = string(50,'0');
        big sum = 0;
        for (int i : p) {
            ans = add(ans,(big)(i * sum));
            sum += i;
        }
        reverse(all(ans));
        while (ans.size() and ans.back() == '0') ans.pop_back();
        reverse(all(ans));
        if (ans.empty()) cout << "0";
        else 
        cout << ans;
    } else {
        vector<int> p(m);
        for (int j = 0; j < m; ++j) {
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                if (v[i][j]) cur++;
                else {
                    p[j] += cur * (cur - 1) / 2;
                    cur = 0;
                }
            }
            if (cur) p[j] += cur * (cur - 1) / 2;
        }
        string ans = string(50,'0');
        big sum = 0;
        for (int i : p) {
            ans = add(ans,(big)(i * sum));
            sum += i;
        }
        reverse(all(ans));
        while (ans.size() and ans.back() == '0') ans.pop_back();
        reverse(all(ans));
        
        if (ans.empty()) cout << "0";
        else 
        cout << ans;
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