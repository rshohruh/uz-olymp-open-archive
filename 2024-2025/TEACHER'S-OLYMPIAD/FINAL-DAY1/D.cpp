#include <iostream>
using namespace std;

int main(){
    int t;
    for(cin >> t; t > 0; -- t){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        auto dist = [&](int n){
            int x = d / n * n;
            return min(d - x, x + n - d);
        };
        
        int x = dist(a);
        x = min(x, dist(b));
        x = min(x, dist(c));
        
        int y = (dist(a) == x) + (dist(b) == x) + (dist(c) == x);
        
        cout << x;
        if(y > 1) cout << " Istaganingizni tanlashingiz mumkin!";
        cout << '\n';
    }
    return 0;
}