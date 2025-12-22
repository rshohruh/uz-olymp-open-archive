#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    int x = (k + 1) / 2;
    cout << (n + x - 1) / x << endl;
    return 0;
}