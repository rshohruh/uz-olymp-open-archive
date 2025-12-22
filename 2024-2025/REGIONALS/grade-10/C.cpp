#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
string fileio = "";

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll infl = 1e18;
const int maxn = 1e5 + 1;

int main(){
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n + 1);
    
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    
    sort(all(a));
    ll ans = 0;
    for(int i = n; i > 0; i --){
        ll dif = a[i] - a[i - 1];
        ll cnt = n - i + 1;
        ll minus = min(dif, k / cnt);
        
        ans += (a[i] - minus + 1 + a[i]) * minus * cnt / 2;
        k -= minus * cnt;
        if(k == 0) break;
        if(minus == dif){
            continue;
        }
        ans += 1ll * k * (a[i] - minus);
        break;
    }

    cout << ans;
}