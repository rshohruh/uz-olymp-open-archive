#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int fizz=0;
  int buzz=0;
  int fizzbuzz=0;
  for(int i=1; i<=n; i++){
    if(i%5==0 and i%3==0){
      fizzbuzz=fizzbuzz+1;
    }else if(i%5==0){
      buzz++;
    }else if(i%3==0){
      fizz++;
    }
  }
  cout<<fizz<<" "<<buzz<<" "<<fizzbuzz;
  return 0;
}