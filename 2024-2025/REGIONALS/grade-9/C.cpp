#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> pv;
    pv.emplace_back(0);
    for(int i = 0; i < n; ++i) {
        int x, y, p; cin >> x >> y >> p;
        int befy = x - 1;
        if(i > 0 && (x - 1) * (100LL - pv.back()) > x * (100LL - p)) {
            cout << "YES";
            return 0;
        }
        pv.emplace_back(p);
    }

    cout << "NO";
}