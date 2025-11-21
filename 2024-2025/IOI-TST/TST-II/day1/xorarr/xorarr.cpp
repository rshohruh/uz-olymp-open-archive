#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = 0;

    for (int bit = 29; bit >= 0; --bit) {
        int pos = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (a[i] & (1 << (bit + 1))) pos = i;
            a[i] &= (1 << (bit + 1)) - 1;
        }

        inplace_merge(a.begin(), a.begin() + pos, a.end());

        long long cnt = 0;
        int l = 0, r = n - 1;

        while (l <= r) {
            while (l <= r && a[l] + a[r] < (1 << bit)) l++;
            if (l <= r) cnt += r - l + 1;
            r--;
        }

        l = 0; r = n - 1;
        while (l <= r) {
            while (l <= r && a[l] + a[r] < (1 << (bit + 1))) l++;
            if (l <= r) cnt += r - l + 1;
            r--;
        }

        l = 0; r = n - 1;
        while (l <= r) {
            while (l <= r && a[l] + a[r] < ((1 << (bit + 1)) | (1 << bit))) l++;
            if (l <= r) cnt += r - l + 1;
            r--;
        }

        if (cnt & 1) ans |= (1 << bit);
    }

    cout << ans << "\n";
    return 0;
}
