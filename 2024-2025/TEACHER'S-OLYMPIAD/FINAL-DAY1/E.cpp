#include <iostream>
#include <vector>
using namespace std;
const int mod = 1000000007;
int phi(int n){
    int res = n;
    for(int i = 2; i * i <= n; i ++)
        if(n % i == 0){
            res -= res / i;
            while(n % i == 0) n /= i;
        }
    if(n > 1) res -= res / n;
    return res;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    
    long long res = 0;
    for(int i = 2; i <= n; i ++)
        res += phi(i);
    cout << res * 2 + 1;
   
    return 0;
}