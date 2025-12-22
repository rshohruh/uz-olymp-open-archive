#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
int main(){
    int n; cin >> n;
    vector<int> mn(10, inf);
    int s = 0;
    for(int i = 0; i < n; i ++){
        int x; cin >> x;
        if(x % 10) mn[x % 10] = min(mn[x % 10], x);
        s += x;
    }
    if(s % 10){
        cout << s;
    }else{
        cout << max(0,s - *min_element(mn.begin(), mn.end()));
    }
}