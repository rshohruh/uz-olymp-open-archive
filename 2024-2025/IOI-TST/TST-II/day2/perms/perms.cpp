#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0;
        return 0;
    }

    n /= 2;
    long long k = (long long) sqrt((long double) n);

    if (k * k != n) {
        int cnt = 0;
        for (long long i = 1; i <= k; ++i) {
            if (n % i == 0) cnt++;
        }
        cout << 2 * cnt;
    } else {
        int cnt = 1;
        for (long long i = 1; i < k; ++i) {
            if (n % i == 0) cnt++;
        }
        cout << 2 * cnt - 1;
    }

    return 0;
}
