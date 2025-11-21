#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int ask(const string &s) {
    cout << "? " << s << '\n';
    cout.flush();

    int x;
    if (!(cin >> x)) {
        exit(0);
    }
    if (x == -1) {
        exit(0);  // required by the statement
    }
    return x;
}

void answer(int x) {
    cout << "! " << x << '\n';
    cout.flush();
}

void solve(int n, int d) {
    assert(6 * d <= n);

    d *= 2;
    int total_groups = d;
    int high_bit = 0;
    for (int i = 0; i < 30; ++i)
        if ((total_groups >> i) & 1)
            high_bit = i;

    int rs = (n / d + 1) / 2;
    int dest_gr = 0;
    int shakings_in_gr = 0;

    // First phase: determine the group containing the friend
    for (int bit = 0; bit <= high_bit; ++bit) {
        string s(n, 'L');

        for (int gr = 1; gr <= d; ++gr) {
            if ((gr >> bit) & 1) {
                for (int j = 0; j < rs; ++j) {
                    int pos = d * j + gr - 1;
                    if (pos < n) s[pos] = 'R';
                }
            }
        }

        int result = ask(s);
        if (result > 0) {
            dest_gr |= (1 << bit);
            shakings_in_gr = result;
        }
    }
    dest_gr--;  // groups are 0-indexed internally

    int tot = 0;
    for (int i = 0; i < n; ++i)
        if (i % d == dest_gr)
            ++tot;

    int id = shakings_in_gr / 2;

    // If the number of handshakes in the group is even, we already know the index
    if (shakings_in_gr % 2 == 0) {
        answer(d * id + dest_gr + 1);
        return;
    }

    // Second phase: distinguish between symmetric positions inside the group
    string s(n, 'L');
    for (int k = id; d * k + dest_gr < n; ++k)
        s[d * k + dest_gr] = 'R';

    if (d * (id - 1) + dest_gr >= 0) {
        s[d * (id - 1) + dest_gr] = 'R';
        s[d * id + dest_gr] = 'L';
    } else {
        s[d * (id + 1) + dest_gr] = 'L';
    }

    if (ask(s) == 0)
        id = tot - id - 1;

    answer(d * id + dest_gr + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, d;
        cin >> n >> d;
        solve(n, d);
    }
    return 0;
}
