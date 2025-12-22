#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

const int N = 100001;
int col[N];
vector<int> gr[N];
int cnt[N][2]; // 0 - Стартует Абдулла, 1 - Стартует Темур
int ans[N][2];

void dfs1(int v, int p) {
    if (gr[v].size() == 1 && gr[v][0] == p) {
        cnt[v][1] = (col[v] == 1);
        cnt[v][0] = (col[v] == 2);
        return;
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs1(u, v);
        cnt[v][0] += (cnt[u][1] == 0);
        cnt[v][1] += (cnt[u][0] == 0);
    }
}

void trans(int v, int u) {
    if (gr[v].size() == 1) {
        cnt[v][1] = (col[v] == 1);
        cnt[v][0] = (col[v] == 2);
    } else {
        cnt[v][0] -= (cnt[u][1] == 0);
        cnt[v][1] -= (cnt[u][0] == 0);
    }
    if (gr[u].size() == 1){
        cnt[u][0] = (cnt[v][1] == 0);
        cnt[u][1] = (cnt[v][0] == 0);
    } else{
        cnt[u][0] += (cnt[v][1] == 0);
        cnt[u][1] += (cnt[v][0] == 0);
    }
}

void dfs2(int v, int p) {
    ans[v][0] = cnt[v][0];
    ans[v][1] = cnt[v][1];
    for (int u : gr[v]) {
        if (u == p) continue;
        int a = cnt[v][0], b = cnt[v][1], c = cnt[u][0], d = cnt[u][1];
        trans(v, u);
        dfs2(u, v);
        trans(u, v);
    }
}
 
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> col[i];
    if (n == 1) {
        if (col[1] == 1) {
            cout << "1 T T";
        } else {
            cout << "1 A A";
        }
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
        if (ans[i][0]) cout << "A ";
        else cout << "T ";
        if (ans[i][1]) cout << "T\n";
        else cout << "A\n";
    }
}