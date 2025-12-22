#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    int n; cin >> n;
    int dx, dy; cin >> dx >> dy;

    vector<int> X(n), Y(n);
    for(int i = 0; i < n; ++i) cin >> X[i];
    for(int i = 0; i < n; ++i) cin >> Y[i];

    map<pair<int, int>, map<int, vector<int>>> mp;
    for(int i = 0; i < n; ++i) {
        int x = X[i] - dx, y = Y[i] - dy;
        if(x == y && x == 0) {
            cerr << "WTF\n";
        }

        int gc = gcd(abs(x), abs(y));
        x /= gc; y /= gc;

        int tx = x, ty = y;
        if(tx < 0 || (tx == 0 && ty < 0)) {
            tx = -tx;
            ty = -ty;
        }

        mp[{tx, ty}][int((x > 0) || (x == 0 && y > 0))].emplace_back(i + 1);
    }

    int tot = 0;
    vector<int> ans;
    for(auto& [gr, vc]: mp) {
    	reverse(vc[0].begin(), vc[0].end());
        tot += 2 * min(vc[0].size(), vc[1].size()) - (vc[0].size() == vc[1].size());
        int cur = (vc[0].size() > vc[1].size() ? 0 : 1);
        while(!vc[0].empty() || !vc[1].empty()) {
            if(!vc[cur].empty()) {
                ans.emplace_back(vc[cur].back());
                vc[cur].pop_back();
            }
            cur ^= 1;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << tot << '\n';
    for(int x: ans) cout << x << ' ';
}