#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define pb push_back
#define all(a) a.begin(),a.end()

void solve(){
     int k,n; cin >> k >> n;
     vector<int> vec(n);
     for(auto &x : vec) cin >> x;
     sort(all(vec));
     reverse(all(vec));
     
     for(int i = 0; i < n; i++){
             k -= vec[i];
             if(k <= 0){
                  cout << i+1; return;
                  }
     }
     
}

signed main(){
       cin.tie(0)->sync_with_stdio(false);
       int t = 1;
       
       for(int i = 0; i < t; i++) solve();
}