#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cmath>
#include <iomanip>
#include <unordered_set>
#include <fstream>
#define int long long
#define fs first
#define ss second
#define pii pair <int, int>
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vii vector <vi>
const int inf = 1e18;
const int mod = 1e9 + 9;
const int N = 1000000;
const double eps = 1e-8;
using namespace std;

bool isprime(int n){
   if (n < 2) return false;
   if (n == 2) return true;
   if (n % 2 == 0) return false;
   for (int i = 3; i * i <= n; i += 2)
      if (n % i == 0)
         return false;
   return true;
}

int calc(string s){
   if (s.empty() || !isprime(stoll(s))) return 0;
   int n = stoll(s);
   s = to_string(n);
   int res = max(calc(s.substr(1)), calc(s.substr(0, s.size() - 1)));
   for (int i = 1; i + 1 < s.size(); ++ i)
      res = max(res, calc(s.substr(0, i) + s.substr(i + 1)));
   return res + 1;
}

void solve(){
   int n; cin >> n;
   cout << calc(to_string(n));
}

signed main(){
   cin.tie(nullptr)->ios::sync_with_stdio(false);
   int t = 1;
   // cin >> t;
   while (t --)
      solve();
   return 0;
}