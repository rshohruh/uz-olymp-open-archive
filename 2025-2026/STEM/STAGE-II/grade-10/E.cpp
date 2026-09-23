#include <bits/stdc++.h>
using namespace std;

const int mxN = 1001, inf = 1e8;
vector<int> g[mxN];
int dp[mxN][2];

int memo[mxN][2];
int tmp[mxN][2];

void dfs(int u){

    for(auto v : g[u])
        dfs(v);

    sort(g[u].begin(),g[u].end());

    if(g[u].empty()){
        dp[u][0] = dp[u][1] = 0; return;
    }

    int n = (int) g[u].size();

    for(int i = 0; i <= n; i++){
        memo[i][0] = memo[i][1] = -inf;
    }

    memo[0][0] = memo[0][1] = 0;

    for(auto v : g[u]){
        for(int i = 0; i <= n; i++)
            tmp[i][0] = tmp[i][1] = -inf;

        for(int i = 0; i <= n; i++){
            if(i < n){
                tmp[i+1][0] = max(tmp[i+1][0],memo[i][0]-v+dp[v][0]);
                tmp[i+1][1] = max(tmp[i+1][1],memo[i][1]-v+dp[v][0]);
            }

            if(i){
                tmp[i-1][0] = max(tmp[i-1][0],memo[i][0]+v+dp[v][0]);
                tmp[i-1][1] = max(tmp[i-1][1],memo[i][1]+v+dp[v][0]);
            }

            tmp[i][0] = max(tmp[i][0],memo[i][0]+max(dp[v][0],dp[v][1]));
            tmp[i][1] = max(tmp[i][1],memo[i][1]+max(dp[v][0],dp[v][1]));

            if(u != 1){
                tmp[i][1] = max(tmp[i][1],memo[i][0]+abs(u-v)+dp[v][0]); 
            }
        }

        for(int i = 0; i <= n; i++){
            memo[i][0] = tmp[i][0];
            memo[i][1] = tmp[i][1];
        }
    }

    dp[u][0] = memo[0][0];
    dp[u][1] = memo[0][1];

}

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N; cin >> N;
    for(int i = 2; i <= N; i++){
        int p; cin >> p;
        g[p].emplace_back(i);
    }

    dfs(1);

    cout << dp[1][0];

}