#include <bits/stdc++.h>
#define int long long
using namespace std;

void ask(int y){
    cout << "? " << y << "\n";
    cout.flush();
}

void ans(int x){
    cout << "! "  << x << "\n";
    cout.flush();
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, q;cin >> t >> q;
    while (t--){
        if (q == 1){
            ask(0);
            char c, lr;int w;
            cin >> c >> w >> lr;
            if (lr == 'R'){
                ans(5-w);
            }else ans(w);
        }else if (q == 2){
            ask(0);
            char c, lr;int w;
            cin >> c >> w >> lr;
            if (c == 'B'){
                int pred = 1;
                if (lr == 'L'){
                    if (w == 1) pred = 1;
                    else pred = 2;
                }
                else{
                    if (w == 2) pred = 3;
                    else pred = 4;
                }
                ask(16-pred);
                cin >> c >> w >> lr;
                if (c == 'B'){
                    ans(pred);
                }else if (lr == 'R' && w == 3) ans(pred+4);
                else if (lr == 'L' && w == 2) ans(pred+8);
                else ans(pred+12);
            }else{
                int pred;
                if (lr == 'L'){
                    if (w == 1) pred = 29;
                    else if (w == 2) pred = 30;
                    else pred= 31;
                }else{
                    if (w == 1) pred = 34;
                    else if (w == 2) pred = 33;
                    else pred= 32;
                }
                ask(17-pred);
                cin >> c >> w >> lr;
                if (c == 'E'){
                    ans(pred);
                }else if (lr == 'R' && w == 2) ans(pred-6);
                else if (lr == 'L' && w == 1) ans(pred-12);
            }
        }else{
            ask(0);
            char c, lr;int w;
            cin >> c >> w >> lr;
            if (c == 'B'){
                int pred = 1;
                if (lr == 'L'){
                    if (w == 1) pred = 1;
                    else pred = 2;
                }
                else{
                    if (w == 2) pred = 3;
                    else pred = 4;
                }
                ask(16-pred);
                cin >> c >> w >> lr;
                if (c == 'B'){
                    ans(pred);
                }else if (lr == 'R' && w == 3) ans(pred+4);
                else if (lr == 'L' && w == 2) ans(pred+8);
                else ans(pred+12);
            }else{
                int pred;
                if (lr == 'L'){
                    if (w == 1) pred = 1;
                    else if (w == 2) pred = 2;
                    else pred= 3;
                }else{
                    if (w == 1) pred = 6;
                    else if (w == 2) pred = 5;
                    else pred= 4;
                }
                bool fnd = 0;
                for (int i = 1; i<=4;i++){
                    ask(-pred-6-(i-1)*12);
                    cin >> c >> w >> lr;
                    if (c == 'B'){
                        fnd = 1;
                        if (lr == 'L'){
                            ans(pred+4+12*i);
                        }else ans(pred+10+12*i);
                        break;
                    }
                }
                if (!fnd){
                    ans(64+pred);
                }
            }
        }
    }
}