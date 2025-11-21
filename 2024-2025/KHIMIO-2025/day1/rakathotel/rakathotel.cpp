#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    vector<int> res;
    for(int &x:a) cin >> x;
    sort(a.begin(), a.end());
    auto check = [&](int k){
        if(a.back() < k) return false;
        int i = (int)(lower_bound(a.begin(), a.end(), k) - a.begin());
        if(n - i >= k) return true;
        int v = a[i] - (n - i);
        k -= n - i;
        -- i;
        while(k > 0 && a[i] >= v){
            -- v;
            -- i;
            -- k;
        }
        return k == 0;
    };
     
    auto getmin = [&](int k){
        multiset<int> s(a.begin(), a.end());
        auto it = s.lower_bound(k);
        res.push_back(*it);
        s.erase(it);
        int x = res[0];
        while(res.size() < k){
            -- x;
            it = s.lower_bound(x);
            res.push_back(*it);
            s.erase(it);
        }
    };
     
    auto getmax = [&](int k){
        int L = n - k, R = n - 1, M;
        while(L != R){
            M = (L + R + 1) / 2;
            bool f = true;
            int v = a[M];
            for(int i = n - 1; i >= n - k; -- i){
                if(i == M) continue;
                --v;
                if(a[i] < v){
                    f = false;
                    break;
                }
            }
            if(f) L = M;
            else R = M - 1;
        }
        return L;
    };
     
    int L = 1, R = n, M;
    while(L < R){
        M = (L + R + 1) / 2;
        if(check(M)) L = M;
        else R = M - 1;
    }
    cout << L << '\n';
    if(t == 1){
        int id = getmax(L);
        cout << a[id];
        for(int i = n - 1; i >= n - L; -- i){
            if(i == id) continue;
            cout << " " << a[i];
        }
    }
    return 0;
}