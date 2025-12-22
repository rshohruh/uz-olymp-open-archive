#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define endl '\n'
#define print(a) for(auto x : a) cout << x << ' '; cout << endl;

const int mod = 1e9 + 9;

struct SegTree {

    int size = 1;
    vector<int> sums;

    SegTree (int n){
        while(size < n)
            size <<= 1;
        sums.resize(size << 1);
    }

    int get(int l, int r, int x, int lx, int rx){
        if(l <= lx and rx <= r)
            return sums[x];
        if(r <= lx or rx <= l)
            return 0;
        int mid = (lx + rx) >> 1;
        return (get(l, r, (x << 1) + 1, lx, mid) + get(l, r, (x << 1) + 2, mid, rx)) % mod;
    }

    int get(int l, int r){
        return get(l, r, 0, 0, size);
    }

    void set(int i, int p, int x, int lx, int rx){
        if(rx - lx == 1){
            sums[x] = (sums[x] + p) % mod;
            return;
        }
        int mid = (lx + rx) >> 1;
        if(i < mid)
            set(i, p, (x << 1) + 1, lx, mid);
        else
            set(i, p, (x << 1) + 2, mid, rx);
        sums[x] = (sums[(x << 1) + 1] + sums[(x << 1) + 2]) % mod;
    }

    void set(int index, int p){
        set(index, p, 0, 0, size);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < n - 1; i ++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> parent(n + 1), id(n + 1);
    queue<int> q;
    q.push(1);
    int j = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        id[x] = j;
        j ++;

        for(auto y : graph[x]){
            if(parent[x] != y){
                parent[y] = x;
                q.push(y);
            }
        }
    }
    vector<array<int, 2>> rng(n + 1);
    for(int i = 1; i <= n; i ++){
        if(graph[i][0] != parent[i])
            rng[i][0] = id[graph[i][0]];
        else if(graph[i].size() > 1)
            rng[i][0] = id[graph[i][1]];
        if(graph[i].back() != parent[i])
            rng[i][1] = id[graph[i].back()];
        else if(graph[i].size() > 1)
            rng[i][1] = id[graph[i][(int)graph[i].size() - 2]];
    }
    vector<int> out(n + 1);
    SegTree st(n + 2);
    int t;
    cin >> t;
    while(t --){
        char c;
        cin >> c;
        int x;
        cin >> x;
        if(c == '+') {
            int cur = a[x] + (x == 1 ? 0 : out[parent[x]]);
            if(rng[x][0] != 0)
                cur += st.get(rng[x][0], rng[x][1] + 1);
            cur %= mod;
            out[x] = (out[x] + cur) % mod;
            st.set(id[x], cur);
        }
        else {
            int cur = a[x] + (x == 1 ? 0 : out[parent[x]]);
            if(rng[x][0] != 0)
                cur += st.get(rng[x][0], rng[x][1] + 1);
            cur %= mod;
            cout << cur << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
        solve();
}