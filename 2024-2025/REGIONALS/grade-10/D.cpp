#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, m, res = 1e9, k;
    cin >> n >> m;
    vector<int> a(m);
    for(int &x:a) cin >> x;
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < m; ++ i)
        res = min(res, i+a[i]);


    cout << max(m - min(res, n-1), 0);
    return 0;
}