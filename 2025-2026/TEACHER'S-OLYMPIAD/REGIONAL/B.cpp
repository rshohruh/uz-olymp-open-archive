#include <iostream>
using namespace std;

int main(){
    auto calc = [](string s){
        int res = 1;
        for(char c:s) res = res * (c - 64) % 47;
        return res;
    };

    string a, b;
    cin >> a >> b;
    cout << (calc(a) == calc(b) ? "Welcome" : "Try again") << '\n';
    return 0;
}