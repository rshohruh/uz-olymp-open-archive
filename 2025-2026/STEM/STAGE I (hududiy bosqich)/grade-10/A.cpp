#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define pb push_back
#define all(a) a.begin(),a.end()

void solve(){
     int a,b; cin >> a >> b;
     cout << (b+a-1)/a;
     
}

signed main(){
       cin.tie(0)->sync_with_stdio(false);
       int t = 1;
       
       for(int i = 0; i < t; i++) solve();
}