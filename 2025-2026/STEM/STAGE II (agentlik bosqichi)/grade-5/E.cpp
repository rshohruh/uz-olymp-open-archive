#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string s;
    for(int i = 0; i < m; ++ i){
        cin >> s;
        char b = '.';
        for(char c:s){
            if(isdigit(c))
                cout << string(c - 48, b);
            b = ".X"[b == '.'];
        }
        cout << '\n';
    }
    return 0;
}