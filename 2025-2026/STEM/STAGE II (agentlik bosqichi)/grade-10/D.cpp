#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+1;
vector<int> g[mxN];
int deg[mxN];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N,M; cin >> N >> M;

    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v;
        g[u].emplace_back(v);
        deg[v]++;
    }

    priority_queue<int> pq;
    for(int i = 1; i <= N; i++) if(deg[i]==0)
        pq.push(-i);

    while(!pq.empty()){
        auto u = -pq.top(); pq.pop();
        cout << u << ' ';
        for(auto v : g[u]) if(--deg[v]==0)
            pq.push(-v);
    }

}