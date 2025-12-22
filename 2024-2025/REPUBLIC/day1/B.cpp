#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    sort(all(a));
    int cnt = 0;
    for(int i = n - 1; i >= 0; i --){
        if(i + 1 < n and a[i + 1] == a[i])
            cnt ++;
        else
            cnt = 0;
        cout << (n - i - 1) + (n - i) * a[i] - cnt << ' ';
    }
}