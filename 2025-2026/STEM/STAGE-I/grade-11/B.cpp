#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define ln "\n"
const ll INF = 2e18;
using namespace std;

void solve(){
    ll n; cin >> n;
    ll w=30, l=30, r=1200;
    for (ll i=0; i<n; i++){
        char x; cin >> x;
        if(x=='W') {
            r+=w; w--; w=max(10ll, w); l=30;
        }else if(x=='L'){
            r-=l; l--; l=max(l, 10ll); w=30;
        }else{
            l=w=30;
        }
        r=max(r, 0ll);
    }
    cout << r << ln;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}