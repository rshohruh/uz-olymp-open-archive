#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> b;
	int cur=0;
	for(int i=n-1;i>=0;i--)
	{
		
		if(a[i]>=cur) b.push_back(a[i]);
		cur=max(cur, a[i]);
	}
	for(int i=b.size()-1;i>=0;i--) 
	{
		if(i!=0) cout<<b[i]<<" ";
		else cout<<b[i];
	}
}
int main()
{
	solve();
}