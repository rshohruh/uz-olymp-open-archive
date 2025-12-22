#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 4e5 + 5;
vector<int> par(MAXN), r(MAXN, 1),order;
vector<vector<pair<int, int>>> g(MAXN);

int trees = MAXN;

int get(int x) {
    return par[x] = (x == par[x] ? x : get(par[x]));
}

void unite(int x, int y) {
    x = get(x); y = get(y);
    if(x == y) return;

    if(r[x] > r[y]) swap(x, y);
    par[x] = y;
    r[y] += r[x];
    r[x] = 0;
    
};

int n;
vector<pair<int, int>> edges;
vector<int> ans_edge;

void dfs(int x) {
    while(!g[x].empty()) {
        auto [z, id] = g[x].back();
        g[x].pop_back();

        if(ans_edge[id] != -1) continue;
        ans_edge[id] = z;

        dfs(z);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    iota(par.begin(), par.end(), 0);
    //iota(order.begin(), order.end(), 0);
    
    cin >> n;
    ans_edge.assign(n + 1, -1);

    edges.emplace_back(0, 0);
    for(int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);

        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);

        if(get(a) == get(b)) order.emplace_back(a);
        unite(a, b);
    }

    //reverse(order.begin(), order.end());

    for(int x: order) {
        dfs(x);
    }
    for(int i = 0; i < MAXN; i ++){
       dfs(i);
    }

    set<int> st;
    string ans = "";
    for(int i = 1; i <= n; ++i) {
        assert(ans_edge[i] != -1);
        if(ans_edge[i] == edges[i].first) {
            ans.push_back('a');
            st.insert(edges[i].first);
        } else {
            ans.push_back('b');
            st.insert(edges[i].second);
        }
    }

    cout << st.size() << endl;
    cout << ans << endl;
}