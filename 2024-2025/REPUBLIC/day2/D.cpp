#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define endl '\n'
#define print(a) for(auto x : a) cout << x << ' '; cout << endl;

const int N = 5e5 + 5, nN = 2e5;

int cnt[N], F[N], arr[nN];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    for(int i = 0; i < n; i ++){
        for(int j = 2; j * j <= arr[i]; j ++){
            while(arr[i] % j == 0){
                cnt[j] ++;
                arr[i] /= j;
            }
        }
        if(arr[i] > 1 and arr[i] < N)
            cnt[arr[i]] ++;
    }
    int q, M, a, b, c;
    cin >> q >> M >> a >> b >> c;
    for(int i = 2; i <= M + 2; i ++){
        int mn = 1e9, x = i;
        for(int j = 2; j * j <= x; j ++){
            int c = 0;
            while(x % j == 0){
                c ++;
                x /= j;
            }
            if(c > 0)
                mn = min(mn, cnt[j] / c);
        }
        if(x > 1)
            mn = min(mn, cnt[x]);
        F[i] = mn;
    }
    
    int ans = 0;
    for(int i = 0; i < q; i ++){
        a = (a * b + c) % M;
        ans += a ^ F[a + 2];
    }
    cout << ans;
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