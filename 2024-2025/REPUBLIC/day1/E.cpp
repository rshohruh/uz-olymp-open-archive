#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define endl '\n'
#define print(a) for(auto x : a) cout << x << ' '; cout << endl;

vector<vector<array<int, 2>>> graph;

struct LCA {

    vector<vector<int>> lca, val;
    vector<int> Degree;

    void dfs(int n, int p){
        for(auto x : graph[n]){
            if(x[0] != p){
                Degree[x[0]] = Degree[n] + 1;
                lca[x[0]][0] = n;
                val[x[0]][0] = x[1];
                dfs(x[0], n);
            }
        }
    }

    LCA (){
        int n = (int)graph.size();
        lca.resize(n, vector<int> (18));
        val.resize(n, vector<int> (18));
        Degree.resize(n);

        dfs(1, -1);
        for(int i = 1; i <= 17; i ++)
            for(int j = 1; j < n; j ++)
                lca[j][i] = lca[lca[j][i - 1]][i - 1], val[j][i] = val[j][i - 1] + val[lca[j][i - 1]][i - 1];
    }

    int binary_jumping(int &n, int d){
        int res = 0;
        for(int i = 17; d > 0; i --){
            if(d >= (1 << i)){
                res += val[n][i];
                n = lca[n][i];
                d -= (1 << i);
            }
        }
        return res;
    }

    int get(int a, int b){
        if(Degree[a] < Degree[b])
            swap(a, b);
        int dist = binary_jumping(a, Degree[a] - Degree[b]);
        for(int i = 17; i >= 0; i --){
            if(lca[a][i] != lca[b][i]){
                dist += val[a][i] + val[b][i];
                a = lca[a][i];
                b = lca[b][i];
            }
        }
        if(a != b)
            dist += val[a][0] + val[b][0];
        return dist;
    }
};

int timer = 0;
vector<int> tin;

void dfs(int n, int p){
    tin[n] = timer ++;
    for(auto x : graph[n])
        if(x[0] != p)
            dfs(x[0], n);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    graph.resize(n + 1);
    for(int i = 0; i < n - 1; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    tin.resize(n + 1);
    dfs(1, -1);
    vector<int> p(n);
    for(int i = 1; i <= n; i ++)
        p[tin[i]] = i;
    int t;
    cin >> t;
    LCA lca;
    set<int> nodes;
    int sum = 0;
    while(t --){
        char c;
        cin >> c;
        int x;
        cin >> x;
        if(c == '+'){
            if(nodes.size() != 0){
                auto it = nodes.lower_bound(tin[x]);
                if(it == nodes.begin())
                    it = nodes.end();
                it --;
                int a = p[*it];
                it ++;
                if(it == nodes.end())
                    it = nodes.begin();
                int b = p[*it];
                sum -= lca.get(a, b);
                sum += lca.get(a, x) + lca.get(b, x);
            }
            nodes.insert(tin[x]);
        }
        else{
            if(nodes.size() != 1){
                auto it = nodes.find(tin[x]);
                if(it == nodes.begin())
                    it = nodes.end();
                it --;
                int a = p[*it];
                it ++;
                if(it == nodes.end())
                    it = nodes.begin();
                it ++;
                if(it == nodes.end())
                    it = nodes.begin();
                int b = p[*it];
                sum -= lca.get(a, x) + lca.get(b, x);
                sum += lca.get(a, b);
            }
            nodes.erase(tin[x]);
        }
        cout << sum << endl;
    }
}