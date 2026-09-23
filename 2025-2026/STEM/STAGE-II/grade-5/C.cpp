#include <bits/stdc++.h>
using namespace std;

#define int long long

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


void t_main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    int s = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        s += a[i];
    }
    int s1 = 0;
    for(int i = 1; i < n; ++ i){
        s1 += a[i];
        if(s1 * 2 == s){
            cout << i;
            return ;
        }
    }
    cout << -1;
}

signed main(){    
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    // cin >> t;    
    // assert(t == 1000);
    while(t --){
        t_main();
        cout << '\n';
    }
    return 0;
}