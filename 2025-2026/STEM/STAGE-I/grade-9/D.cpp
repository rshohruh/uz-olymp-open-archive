#include <bits/stdc++.h>

using namespace std;

#define int long long
constexpr int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (count(s.begin(), s.end(), 'S') == count(s.begin(), s.end(), 'M')) {
            multiset<int> st;
            int ad = 0, p = 0, c = 0;
            for (char i : s) {
                if (i == 'S') p++;
                else p--;
                st.emplace(p);
            }
            p = 0;
            for (char i : s) {
                if (*st.begin() >= ad) c++;
                if (i == 'S') p++, ad++;
                else p--, ad--;
                st.extract(p);
                st.emplace(ad);
            }
            cout << c << '\n';
        }
        else cout << "0\n";
    }
    return 0;
}