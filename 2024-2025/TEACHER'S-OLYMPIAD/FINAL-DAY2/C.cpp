// author: rshohruh

#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>

#ifdef LOCAL
	#include "debug.hpp"
#else
	#define debug(...) 42
#endif
using namespace std;

#define all(a) (a).begin(), (a).end()
#define int long long
const int mod = 1e9 + 9;
struct FenwickTree{
	vector<int> t;
	int n;
	FenwickTree(int n) : n(n) { t.assign(n+1, 0); }

	void add(int id, int val = 1) {
		for(; id <= n; id += id & -id) 
			(t[id] += val) %= mod;
	}

	int sum(int id) {
		int ans = 0;
		for(; id > 0; id -= id & -id)
			(ans += t[id]) %= mod;
		return ans;
	}

	int sum(int l, int r) {
		return (sum(r) - sum(l-1) + mod) % mod;
	}
};

// #define with_testcases
void t_main(){
	int n; cin >> n;
	vector<int> comp;
	vector<int> a;
	vector<int> b;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		if(x & 1) a.push_back(x);
		else b.push_back(x);
		comp.push_back(x);
	}

	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());
	
	auto get = [&](int x) { return lower_bound(all(comp), x) - comp.begin() + 1; };
	
	auto solve = [&](vector<int> &arr) {
		FenwickTree ft(comp.size());
		int ans = 0;
		for(auto &x: arr) {
			x = get(x);
			int cur = ft.sum(x-1) + 1;
			(ans += cur) %= mod;
			ft.add(x, cur);
		}
		return ans;
	};

	cout << (solve(a) + solve(b) - n + mod) % mod;
}

signed main(){
	signed t = 1;
	cin.tie(nullptr)->sync_with_stdio(false);
	#ifdef with_testcases
		cin >> t;
	#endif
	while(t--){
		t_main();
		cout << '\n';
	}
	return 0;
}