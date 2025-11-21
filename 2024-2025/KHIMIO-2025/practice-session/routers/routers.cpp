#include "routers.h"
#include <vector>
using namespace std;

vector<int> find_routers(int l, int n, int q) {
    vector<int> ans = {0};
    vector<int> memo(l + 1, -1);

    while ((int)ans.size() < n) {
        int cur = ans.back();
        int res = l;

        int prev = -1, last = -1;

        for (int i = 19; i >= 0; --i) {
            if (res - (1 << i) < cur) continue;

            int pos = res - (1 << i);
            int x = memo[pos];
            if (x == -1) {
                x = use_detector(pos);
                memo[pos] = x;
            }

            if (x >= (int)ans.size()) {
                res -= (1 << i);
                if (x == last) {
                    for (int j = res - (1 << i); j < prev; ++j)
                        memo[j] = x;
                }
                last = x;
                prev = res - (1 << i);
            }
        }

        res--;
        ans.push_back(res + res - cur);
    }

    return ans;
}
