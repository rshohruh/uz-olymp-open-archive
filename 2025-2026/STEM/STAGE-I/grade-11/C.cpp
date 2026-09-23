#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define ln "\n"
const ll INF = 2e18;
using namespace std;

void solve(){
    ll n; cin >> n;
    vector<ll> aodd, aeven, bodd, beven;
    for (ll i=0; i<n; i++){
        ll x; cin >> x;
        if (x%2) aodd.push_back(x);
        else aeven.push_back(x);
    }
    for (ll i=0; i<n; i++){
        ll x; cin >> x;
        if (x%2) bodd.push_back(x);
        else beven.push_back(x);
    }
    if (bodd==aodd and beven==aeven){
        cout << "YES\n";
    }else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--){
        solve();
    }
}