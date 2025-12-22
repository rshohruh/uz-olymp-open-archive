#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define endl '\n'
#define print(a) for(auto x : a) cout << x << ' '; cout << endl;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    k --;
    int cur = 0, cnt = 0;
    while(cur < n){
        int mx = -1;
        for(int j = min(n - 1, cur + k); j >= max(0ll, cur - k); j --){
            if(a[j] == 1){
                mx = j;
                break;
            }
        }
        if(mx == -1){
            cout << -1;
            return;
        }
        cur = mx + k + 1;
        cnt ++;
    }
    cout << cnt;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --){
        solve();
        cout << endl;
    }
}