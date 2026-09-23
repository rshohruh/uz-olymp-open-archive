#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, d, x, cnt=0;
    cin>>a>>b>>c>>d;
    while (a!=0 or b!=0 or c!=0 or d!=0) {
        x=a;
        a=abs(a-b);
        b=abs(b-c);
        c=abs(c-d);
        d=abs(d-x);
        cnt++;
    }
    cout<<cnt;
}