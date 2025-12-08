#include <iostream>
using namespace std;

int main(){
    int n, m = 1e9 + 9;
    cin >> n;
    int a = 0, b = 1, A, B;
    for(int i = 1; i <= n; ++ i){
        A = 1LL * (a + b) * (a + b) % m;
        B = (1LL * a * b + 1) % m;
        a = A;
        b = B;
    }

    cout << (a + b) % m;
    return 0;
}