#include <iostream>
using namespace std;
bool a[1000][1000];
bool b[1000];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    auto check = [&](){
        for(int u = 1; u < n; ++ u)
            if(!(a[u][0]^b[u]))
                b[u] ^= 1;
        for(int u = 1; u < n; ++ u)
            for(int v = u + 1; v < n; ++ v)
                if(!(a[u][v] ^ b[u] ^ b[v])) return false;
        return true;
    };
    cin >> n >> m;
    for(int i = 1, x, y; i <= m; ++ i){
        cin >> x >> y;
        --x;
        --y;
        a[x][y] = a[y][x] = true;
    }
    if(check()) cout << "HA";
    else cout << "YO'Q";
    return 0;
}