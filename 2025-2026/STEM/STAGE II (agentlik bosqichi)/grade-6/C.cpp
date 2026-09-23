#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> s(n);

    for(int i = 0; i < n; i ++){
        cin >> s[i];
    }
    if(n < 2){
        cout << -1;
        return;
    }

    vector<int> t, j;
    for(auto c : s){
        if(c % 2 == 0){
            j.push_back(c);
        }
        else{
            t.push_back(c);
        }
    }
    sort(j.begin(), j.end());
    sort(t.begin(), t.end());

    int jl = j.size();
    int tl = t.size();
    if(tl < 2 and jl > 1){
        cout << j[jl - 2] + j[jl - 1];
        return;
    }
    else if(jl < 2 and tl > 1){
        cout << t[tl - 2] + t[tl - 1];
        return;
    }
    else if(jl > 1 and tl > 1){
        cout << max(j[j.size() - 2] + j[j.size() - 1], t[t.size() - 2] + t[t.size() - 1]);
    }
    else{
        cout << -1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
        cout << "\n";
    }

    return 0;
}