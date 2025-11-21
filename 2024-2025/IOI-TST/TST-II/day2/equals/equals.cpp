#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    set<int> distinct;
    multiset<int> duplicates;
    map<int, int> freq;

    ll sum = 0;
    int equalPairs = 0;
    int mex = 1;

    for (int i = 0; i < n; ++i) {
        distinct.insert(a[i]);
        sum += a[i];
        freq[a[i]]++;

        if (i > 0 && a[i] == a[i - 1]) {
            equalPairs++;
            duplicates.insert(a[i]);
        }
    }

    cout << equalPairs << " " << sum << "\n";

    while (m > 0 && !duplicates.empty() && equalPairs > 0) {
        int v = *duplicates.rbegin();
        while (freq[mex]) mex++;

        sum += mex - v;
        freq[v]--;
        freq[mex]++;
        equalPairs--;
        m--;

        distinct.insert(mex);
        cout << equalPairs << " " << sum << "\n";

        duplicates.erase(duplicates.find(v));
    }

    ll best = sum;

    while (m--) {
        int v = *distinct.rbegin();
        while (freq[mex]) mex++;

        sum += mex - v;

        distinct.erase(v);
        distinct.insert(mex);

        freq[v]--;
        freq[mex]++;

        best = min(best, sum);
        cout << equalPairs << " " << best << "\n";
    }

    return 0;
}
