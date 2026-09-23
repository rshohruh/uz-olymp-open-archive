#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n;cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++) cin>>a[i];
	vector<ll> pref(n+1);
	for(ll i=1;i<=n;i++)
	{
		pref[i]=pref[i-1]+a[i-1];
	}
	ll cnt=0;
	for(ll i=0;i<n;i++)
	{
		if(a[i]>pref[i]) cnt++;
	}
	cout<<cnt;
}
int main()
{
	solve();
}