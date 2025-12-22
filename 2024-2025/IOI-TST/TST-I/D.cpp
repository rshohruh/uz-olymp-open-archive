#include <iostream>
using namespace std;
int main() {
    int n, k, y, x;
    cin >> n >> k;
    x = (n + k) / 2;
    y = n - x;
    if (y >= x) cout << string(y, '0') << string(x, '1') << string(y, '0');
    else cout << string(x, '1') << string(y, '0') << string(x, '1');
    return 0;
}