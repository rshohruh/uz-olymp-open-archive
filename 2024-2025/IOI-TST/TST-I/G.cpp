#include <iostream>
#include <vector>
using namespace std;
#define int long long
signed main(){
    int n, m, L = 1, R = 1, dif = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x:a){
        cin >> x;
        if(x > R) R = x;
        if(x != 0) dif ++;
    }
    if(dif > m) cout << -1;
    else if(dif == 0) cout << 0;
    else{
        while(L != R){
            int M = (L + R) >> 1;
            int C = 0;
            for(int &x:a) C += (x + M - 1) / M;
            if(C <= m) R = M;
            else L = M + 1;
        }
        cout << L;
    }
    return 0;
}