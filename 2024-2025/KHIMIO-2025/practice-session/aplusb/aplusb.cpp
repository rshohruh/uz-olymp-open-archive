#include "aplusb.h" 
#include "bits/stdc++.h" 
using namespace std; 
  
int aplusb(int n, std::vector<int> a, std::vector<int> b) { 
    return *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end()); 
}