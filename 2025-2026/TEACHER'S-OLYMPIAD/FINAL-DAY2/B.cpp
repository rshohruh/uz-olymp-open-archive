#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int main(){
  int n, h = 0, d = 0;
  cin >> n;
  assert(1 <= n && n <= 1e5);
  char a, b;
  string q = "SPRLK";
  vector<vector<int> > w(26, vector<int>(26, 0));
  w['S' - 65]['P' - 65] = 1;
  w['S' - 65]['L' - 65] = 1;
  w['P' - 65]['K' - 65] = 1;
  w['P' - 65]['R' - 65] = 1;
  w['R' - 65]['S' - 65] = 1;
  w['R' - 65]['L' - 65] = 1;
  w['L' - 65]['P' - 65] = 1;
  w['L' - 65]['K' - 65] = 1;
  w['K' - 65]['S' - 65] = 1;
  w['K' - 65]['R' - 65] = 1;

  for(int i = 0; i < n; ++ i){
    cin >> a >> b;
    assert(q.find(a) != string::npos && q.find(b) != string::npos);
    if(a == b) d ++;
    else h += w[a-65][b-65];
  }
  cout << h << ' ' << n - (h + d) << ' ' << d;
  return 0;
}