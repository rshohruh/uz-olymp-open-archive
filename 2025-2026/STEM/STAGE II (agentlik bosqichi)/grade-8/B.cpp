#include "bits/stdc++.h"
using namespace std;

int main() {
#ifdef khba
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; cin >> n;
    vector <int> a(n);
    for (int &i : a) cin >> i;
    vector <int> p(n), s(n);
    for (int i = n - 2; i >= 0; --i) s[i] = s[i + 1] + (abs(a[i] - a[i + 1]) == 1);
    for (int i = 1; i < n; ++i) p[i] = p[i - 1] + (abs(a[i] - a[i - 1]) == 1);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        if (i) cnt += p[i - 1];
        if (i + 1 < n) cnt += s[i + 1];
        if (i == 0 or i == n - 1 or abs(a[i - 1] - a[i + 1]) <= 2) cnt += i > 0, cnt += i != n - 1;
        if (cnt == n - 1) return cout << "YES", 0;
    }
    cout << "NO";
}