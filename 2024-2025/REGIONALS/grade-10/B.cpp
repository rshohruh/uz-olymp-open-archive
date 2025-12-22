#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define ln "\n"
using namespace std;

int main(){
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    ll res=min(x, a)+min(y, b);
    x-=min(x, a);
    y-=min(y, b);
    ll res1 = res+min(c, min(x, y));
    cout << res1 << ln;

}