#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, h, c;cin >> n >> h >> c;
    vector<int> a(n);
    for (int i = 0; i< n;i++) cin >> a[i];
    double sum = 0;
    for (int i = 0; i< n;i++){
        sum+=a[i]*h*2;
    }
    cout << ceil(sum*c/500000);
}