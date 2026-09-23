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

struct Fenwick{
    vector<vector<ll>> tr;
    ll n, m, offs;
    Fenwick(ll N, ll M){
        n=N+20; m=M+20;
        offs=10; tr.resize(n+1, vector<ll>(m+1, INF));
    }
    void add(ll _i, ll _j, ll x){
        _i+=offs; _j+=offs;
        for (ll i=_i; i<=n; i+=(-i&i)){
            for (ll j=_j; j<=m; j+=(-j&j)){
                tr[i][j] = min(tr[i][j], x);
            }
        }
    }
    ll get(ll _i, ll _j){
        _i+=offs; _j+=offs; ll res=INF;
        for (ll i=_i; i; i-=(-i&i)){
            for (ll j=_j; j; j-=(-j&j)){
                res = min(tr[i][j], res);
            }
        }
        return res;
    }
};


void solve(){
    ll n, m; cin >> n >> m;
    vector<array<ll, 3>> gr;
    for (ll i=0; i<n; i++){
        for (ll j=0; j<m; j++){
            ll x; cin >> x;
            gr.push_back({x, i, j});
        }
    }
    sort(gr.begin(), gr.end());
    Fenwick tr(n, m); ll res=0;
    for (ll i=0; i<n*m; i++){
        ll qry = tr.get(gr[i][1], gr[i][2]);
        if (qry!=INF) res=max(res, gr[i][1]+gr[i][2]-qry+1);
        tr.add(gr[i][1], gr[i][2], gr[i][1]+gr[i][2]);
    }
    cout << res << ln;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}