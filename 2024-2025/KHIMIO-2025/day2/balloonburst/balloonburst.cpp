#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
 
#define fi first
#define se second
 
const int N = 400500;
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, h, t;
    cin >> n >> h >> t;
    vector<int> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }
 
    int cnt = 0;
    int mx = -1;
    int mx_id = -1;
    for (int i = 0; i < n; i++) {
        int cur = x[i] + t * v[i];
        if (cur >= h) {
            continue;
        }
        cnt += 1;
        if (cur >= mx) {
            mx = cur;
            mx_id = i + 1;
        }
    }
 
    cout << cnt << " " << mx_id << "\n";
}