#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
vector<string> vec[mxN+1];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N,Q; cin >> N >> Q;

    for(int i = 0; i < N; i++){
        string s; cin >> s;
        sort(s.begin(),s.end());
        vec[(int) s.size()].emplace_back(s);
    }

    for(int i = 1; i <= mxN; i++){
        sort(vec[i].begin(),vec[i].end());
    }

    for(int t = 0; t < Q; t++){
        string s; cin >> s;
        sort(s.begin(),s.end());

        int len = (int) s.size();

        if(vec[len].empty()){
            cout << "No\n"; continue;
        }

        auto it = lower_bound(vec[len].begin(),vec[len].end(),s) - vec[len].begin();
        if(it == (int) vec[len].size() || vec[len][it] != s) cout << "No\n";
        else cout << "Yes\n";
    }

}