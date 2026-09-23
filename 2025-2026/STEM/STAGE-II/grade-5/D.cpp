#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, r;
    int k;
    cin >> l >> r >> k;

    long long count = 0;

    for (long long i = l; i <= r; i++) {
        long long n = i;

        if (n < 0) n = -n;

        if (n == 0) {
            if (k == 0) count++;
            continue;
        }

        while (n > 0) {
            if (n % 10 == k) {
                count++;
            }
            n /= 10;
        }
    }

    cout << count << endl;

    return 0;
}