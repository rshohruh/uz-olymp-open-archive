#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int, int> id, mx;
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> x;
        mx[x] = max(mx[x], i - id[x]);
        id[x] = i;
    }
    int res = 1e9;
    for(auto [x, y]:id){
        mx[x] = max(mx[x], n + 1 - y);
        res = min(res, mx[x]);
    }
    cout << res;
    return 0;
}