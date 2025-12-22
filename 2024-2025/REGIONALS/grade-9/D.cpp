#include <iostream>
using namespace std;
int main(){
    long long k, p = 1;
    cin >> k;
    while(p <= k){
        ++ k;
        p *= 2;
    }
    cout << k;
    return 0;
}