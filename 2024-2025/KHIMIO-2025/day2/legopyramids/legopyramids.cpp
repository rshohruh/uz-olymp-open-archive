#include <iostream>
#include <string>

using namespace std;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    auto sum = [](i128 l, i128 r) -> i128 {
        if (l > r) return 0;
        return (l + r) * (r - l + 1) / 2;
    };

    auto calc = [](i128 x) -> i128 {
        return x * (x + 1) * (2 * x + 1) / 6;
    };

    while (T--) {
        long long N, M, A, B, c_ll;
        cin >> N >> M >> A >> B >> c_ll;

        i128 n = N, m = M, a = A, b = B, C = c_ll;

        auto check = [&](i128 mid) -> i128 {
            // total blocks used for mid layers
            if (n == 0 && m == 0) {
                return mid - 1;
            } else if (n == 0) {
                if (b == 0) {
                    return m * (mid - 1);
                } else {
                    return max<i128>(0, mid - m - 1) +
                           sum(max<i128>(1, m - (mid - 1) + 1), m);
                }
            } else if (m == 0) {
                if (a == 0) {
                    return n * (mid - 1);
                } else {
                    return max<i128>(0, mid - 1 - n) +
                           sum(max<i128>(1, n - (mid - 1) + 1), n);
                }
            } else {
                if (a == 0 && b == 0) {
                    return n * m * mid;
                } else if (a == 0) {
                    return (max<i128>(0, mid - m) +
                            sum(max<i128>(1, m - mid + 1), m)) * n;
                } else if (b == 0) {
                    return m * (max<i128>(0, mid - n) +
                                sum(max<i128>(1, n - mid + 1), n));
                } else {
                    i128 nn = n, mm = m;
                    i128 f = min({n, m, mid});
                    i128 ans = f * n * m - sum(1, f - 1) * (n + m) + calc(f - 1);

                    i128 rest = mid - f;
                    n -= f;
                    m -= f;

                    if (!min(n, m)) {
                        if (n > m) swap(n, m);
                        ans += sum(max<i128>(1, m - rest + 1), m);
                        rest -= max(n, m);
                    }

                    ans += max<i128>(0, rest);

                    n = nn;
                    m = mm;
                    return ans;
                }
            }
        };

        i128 L = 0, R = 1;
        while (check(R) < C) R <<= 1;

        while (L < R) {
            i128 mid = (L + R + 1) / 2;
            if (check(mid) <= C) {
                L = mid;
            } else {
                R = mid - 1;
            }
        }

        // convert i128 L to string
        i128 x = L;
        string ans;
        do {
            int digit = int(x % 10);
            ans.push_back(char('0' + digit));
            x /= 10;
        } while (x > 0);
        reverse(ans.begin(), ans.end());

        cout << ans << '\n';
    }

    return 0;
}
