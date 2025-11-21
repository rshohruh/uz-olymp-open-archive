#include <bits/stdc++.h> 
using namespace std; 
  
int getc(char c){ 
    if(c=='L') return 2; 
    return c=='A'; 
} 
  
const int mxn = 2e5+10; 
string val; 
  
  
#define node array<int,8> 
struct SegTree{ 
    int sz; 
    node st[3*mxn], tmp = {0,0,0,0,0,0,0,0}; 
    node merge(node l, node r){ 
        node res = tmp; 
        res[1] = l[1] | r[1]; 
        res[2] = l[2] + r[2]; 
        res[3] = max(l[2] + r[3], l[3]); 
        res[4] = l[4] | r[4]; 
        res[5] = max({l[5],r[5],l[4]+r[1]}); 
        res[6] = max(l[6]+r[2],r[6]); 
        res[7] = max({l[7],r[7],l[6]+r[3]}); 
        return res; 
    } 
  
    void build(int i, int l, int r){ 
        st[i] = tmp; 
        if(l==r){ 
            st[i][1<<getc(val[l])] = 1;  
            st[i][(1<<getc(val[l]))|2] = 1; 
            return; 
        } 
        int m = (l+r)>>1; 
        build(i<<1,l,m); build(i<<1|1,m+1,r); 
        st[i] = merge(st[i<<1],st[i<<1|1]); 
    } 
  
    void init(int n){ 
        sz = n; build(1,1,sz); 
    } 
  
    node query(int i, int l, int r, int s, int e){ 
        if(r < s || l > e) return tmp; 
        if(s <= l && r <= e) return st[i]; 
        int m = (l+r)>>1; 
        return merge(query(i<<1,l,m,s,e),query(i<<1|1,m+1,r,s,e)); 
    } 
  
    int get(int l, int r){ 
        node res = query(1,1,sz,l,r); 
        int smt = 0; 
        for(int i = 0; i < 8; i++){ 
            smt = max(smt,res[i]); 
        } 
        return smt; 
    } 
}st; 
  
void solve(){ 
    int n,q; cin >> n >> q; 
    cin >> val; val = " "+val; 
    st.init(n); 
    while(q--){ 
        int l,r; cin >> l >> r; 
        cout << st.get(l,r) << '\n'; 
    } 
} 
  
int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    int t; cin >> t; 
    while(t--) solve(); 
}