#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cont=1;
void solve(ll s)
{
	if(s==0) 
	{
		cont=0;
		return;
	}
	vector<bool> ok(26, 0);
	for(ll i=0;i<s*s;i++)
	{
		ll v;cin>>v;
		if(v!=0) ok[v-1]=1;
	}
	bool ans=0;
	for(ll i=0;i<26;i++)
	{
		if(ok[i]==0 and ans==0) 
		{
			cout<<"Rad etildi"<<endl;
			ans=1;
		}
	}
	if(ans==0) cout<<"Tasdiqlandi"<<endl;
}
signed main()
{
	while(cont)
	{
		ll s;cin>>s;
		solve(s);
	}
}