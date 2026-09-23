#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define pb push_back
#define all(a) a.begin(),a.end()

void solve(){
     string s; cin >> s;
     
     stack<int> st;
     
     for(auto c : s){
              int a = c-'0';
              if(!st.empty() && st.top()+a==10) st.pop();
              else st.push(a);
     }
     cout << (int) st.size() << '\n';
     
}

signed main(){
       cin.tie(0)->sync_with_stdio(false);
       int t = 1;
       cin >> t;
       for(int i = 0; i < t; i++) solve();
}