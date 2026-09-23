#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define ln "\n"
const ll INF = 2e18;
using namespace std;

void solve(){
    ll n; cin >> n;
    ll mx=INF;
    for (ll i=0; i<n; i++){
        ll x; cin >> x; mx=min(mx, x);
    }
    cout <<mx << ln;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}