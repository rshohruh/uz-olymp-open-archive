#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define ln "\n
using namespace std;

int main(){
    vector<ll> a(3);
    for (ll i=0; i<3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll time = a[0]+a[1];
    ll k; cin >> k;
    if (time/60+(time%60?1:0)<=k) cout << "YES\n";
    else cout << "NO\n";
}