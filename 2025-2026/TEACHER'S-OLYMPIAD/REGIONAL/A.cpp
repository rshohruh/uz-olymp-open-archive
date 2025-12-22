#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
using namespace std;
int main(){
    int t, n, m;
    cin >> t;
    for(int i = 0; i < t; ++ i){
        
        cin >> n >> m;
        cout << (n / 2 >= m ? "Yes" : "No") << '\n';
    }
    return 0;
}