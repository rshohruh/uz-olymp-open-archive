#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;

int binpow(int a, int n){
    int r = 1;
    while(n){
        if(n & 1) r = 1LL * r * a % mod;
        n >>= 1;
        a = 1LL * a * a % mod;
    }
    return r;
}

vector<int> fact;
vector<int> rev_fact;

int C(int n, int k){
    return 1LL * fact[n] * rev_fact[k] % mod * rev_fact[n-k] % mod;
}

int main(){
    int n, m;
    cin >> n >> m;
    fact.resize(n+1);
    rev_fact.resize(n+1);
    fact[0] = rev_fact[0] = 1;
    for(int i = 1; i <= n; ++ i){
        fact[i] = 1LL * fact[i-1] * i % mod;
        rev_fact[i] = binpow(fact[i], mod-2);
    }
    vector<vector<int> > dp(m+1, vector<int>(18));
    for(int x = 1; x <= m; ++ x){
        dp[x][1] = 1;
        for(int j = 2 * x; j <= m; j += x){
            for(int k = 2; k < 18; ++ k)
                dp[j][k] += dp[x][k-1];
        }
    }

    int N = min(n, 17);
    int res = 0;
    for(int x = 1; x <= m; ++ x){
        for(int k = 1; k <= N; ++ k){
            res = (res + 1LL * dp[x][k] * C(n-1, k-1))% mod;
        }
    }
    cout << res;
    return 0;
}