#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define ln "\n"
const ll INF = 2e18;
using namespace std;

void dfs(ll u, vector<ll> &vis, vector<vector<ll>> &A, vector<ll> &comp){
    vis[u]=1; comp.push_back(u);
    for (auto v:A[u]){
        if(!vis[v]) dfs(v, vis, A, comp);
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> A(n+1);
    for (ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    vector<ll> vis(n+1);
    vector<vector<ll>> comp;
    for (ll i=1; i<=n; i++){
        if (!vis[i]){
            comp.push_back(vector<ll>());
            dfs(i, vis, A, comp.back());
        }
    }
    // return;
    ll K = comp.size()-1;
    set<pair<ll, ll>> extra;
    for (ll i=0; i<(ll)comp.size(); i++){
        if (i!=0){
            auto tk = *extra.begin(); extra.erase(extra.begin());
            extra.insert({tk.ff+1, tk.ss});
            extra.insert({1, comp[i][0]});
            for (ll j=1; j<(ll)comp[i].size(); j++){
                extra.insert({0, comp[i][j]});
            }
        }else{
            for (auto v:comp[i]) extra.insert({0, v});
        }
    }
    cout << K << " " << (*extra.rbegin()).ff << ln;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}