#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> A(N),B(N);
    for(auto &x : A) cin >> x;
    for(auto &x : B) cin >> x;

    int ans = 0;

    for(int i = 0; i < N; i++){
        if(B[i]==0){
            ans ^= 1; continue;
        }
        if(A[i]%2==0) continue;
        ans ^= 1;
    }

    cout << (ans?"Odd":"Even");

}