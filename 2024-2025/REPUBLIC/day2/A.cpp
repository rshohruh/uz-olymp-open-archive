#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;cin >> t;
    while (t--){
        int n, m, w;
        cin >> n >> m >> w;
        int h;
        int cnt = w/2;
        h = 2*(n/cnt);
        int left = 0;
        if (n%cnt != 0){
            h+=2;
            left = 2*(cnt*2-(n%cnt)*2);
        }
        if (w%2!=0){
            left += h;
        }
        m-=left;
        if (m > 0){
            h+=m/w;
            if(m%w != 0) h++;
        }
        cout << (h+w)*2 << "\n";
    }
}