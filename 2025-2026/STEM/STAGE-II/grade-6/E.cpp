#include <bits/stdc++.h>
using namespace std;

#define int long long

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


void t_main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n + 2);
    vector<pair<int,int>> b;

    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        if(a[i] == 1){
            int l = max(1ll,i - k);
            int r = min(n,i + k);
            b.emplace_back(l,r);
        }
        a[i] = 0;
    }
    for(int i = 0; i < (int)b.size(); ++ i){
        a[b[i].first] += 1;
        a[b[i].second + 1] -= 1;
    }

    for(int i = 2; i <= n; ++ i) a[i] += a[i - 1];
    int cnt = 0;
    for(int i = 1; i <= n; ++ i) cnt += (a[i] != 0);
    cout << cnt;
}

signed main(){    
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;    
    // assert(t == 1000);
    while(t --){
        t_main();
        cout << '\n';
    }
    return 0;
}