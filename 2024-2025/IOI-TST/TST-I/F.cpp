#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k, m1, m2, med, mn;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    med = (n + 1) / 2;
    while(true){
        m1 = 0;
        m2 = 0;
        mn = 1e9;
        for(int x:a){
            if(x < k) m1 ++;
            else if(x == k) m2 ++;
            if(x != 0 && mn > x) mn = x;
        }
        if(m1 < med && m1 + m2 >= med){
            cout << "YES";
            return 0;
        }
        if(m1 >= med){
            cout << "NO";
            return 0;
        }
        for(int &x:a) if(x != 0) x %= mn;
    }

    return 0;
}