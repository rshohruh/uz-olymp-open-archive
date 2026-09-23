#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
	int n; cin >> n;
	vector <pair<int, int>> arr(n);
	vector <string> s(n);	
	for (int i =0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		if (arr[i].first >= 55 && arr[i].second >= 8) {
			s[i] = "Mayor";
		} else {
			s[i] = "Leytenant";
		}
	}
	for (auto x : s) {
		cout << x << '\n';
	} 
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
//		cout << '\n';
	}
	return 0;
}