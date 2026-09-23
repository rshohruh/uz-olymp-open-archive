#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    vector<int> dp(N+1,INT_MAX);
    dp[0] = 0;

    for(int i = 2; i <= N; i++){
        dp[i] = max(abs(A[i]-A[i-1]),dp[i-2]);
        if(i >= 3){
            dp[i] = min(dp[i],max(dp[i-3],max({A[i],A[i-1],A[i-2]})-min({A[i],A[i-1],A[i-2]})));
        }
    }

    cout << dp[N];
}