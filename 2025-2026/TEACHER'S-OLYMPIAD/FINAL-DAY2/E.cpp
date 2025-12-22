#include <iostream>
#include <cassert>
using namespace std;

int main(){
  int a, b, c;
  if(cin >> a >> b >> c){
    assert(1 <= min(a, min(b, c)) && max(max(a, b), c) <= 1000);
    if(cin >> c) assert(false);
    else
      cout << ((a+b)%(c+1) == 0 ? "Shohruh" : "Husanboy");
  }
  else
    assert(false);
  return 0;
}