#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define pb push_back
#define all(a) a.begin(),a.end()

const int mxn = 305;
int arr[mxn][mxn];
int n,m;



void solve(){
     cin >> n >> m;
     
     for(int i = 1; i <= n; i++)
             for(int j = 1; j <= m; j++)
                     cin >> arr[i][j];
     
     vector<int> col(m);
     iota(all(col),1);
     
     vector<int> temp(max(n,m));
     int ans = 0;
     for(int ind = 1; ind < m; ind++){
             for(int i = 0; i < ind; i++){
                     int a = 0, b = 0;
                     for(int j = 1; j <= n; j++){
                             a += arr[j][col[i]] < arr[j][ind+1];
                             b += arr[j][col[i]] > arr[j][ind+1];
                     }
                     if(a && b){
                          cout << -1; return;
                     }
                     temp[i] = a-b;
             }
             int i = ind-1;
             for(; i >= 0; i--){
                   if(temp[i]>=0) break;
                   swap(col[i+1],col[i]);
                   ans++;
             }
             for(int j = 0; j <= i; j++){
                     if(temp[j] < 0){
                                cout << -1; return;
                     }
             }
     }

     
     vector<int> row(n);
     iota(all(row),1);
     
     for(int ind = 1; ind < n; ind++){
             for(int i = 0; i < ind; i++){
                     int a = 0, b = 0;
                     for(int j = 1; j <= m; j++){
                             a += arr[row[i]][j] < arr[ind+1][j];
                             b += arr[row[i]][j] > arr[ind+1][j];
                     }
                     if(a && b){
                          cout << -1; return;
                     }
                     temp[i] = a-b;
             }
             int i = ind-1;
             for(; i >= 0; i--){
                   if(temp[i]>=0) break;
                   swap(row[i+1],row[i]);
                   ans++;
             }
             for(int j = 0; j <= i; j++){
                     if(temp[j] < 0){
                                cout << -1; return;
                     }
             }
     }
     
     cout << ans;     
     
}

signed main(){
       cin.tie(0)->sync_with_stdio(false);
       int t = 1;
       //n >> t;
       for(int i = 0; i < t; i++) solve();
}