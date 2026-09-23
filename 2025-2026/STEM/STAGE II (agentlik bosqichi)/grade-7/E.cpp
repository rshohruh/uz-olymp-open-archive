#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve()
{
	ll n, k;cin>>n>>k;
	vector<ll> a(n);
	vector<ll> ones;
	for(ll i=0;i<n;i++) 
	{
		cin>>a[i];
		if(a[i]==1) ones.push_back(i);
	}
	vector<ll> inv1;
	vector<ll> inv2;
	for(ll i=0;i<(ll)ones.size();i++)
	{
		inv1.pb(ones[i]-k);
		inv2.pb(ones[i]+k);
	}
	ll cnt=0;
	ll pos=0;
	ll j=0;
	for(ll i=0;i<n;i++)
	{
		if(j==(ll)inv1.size()) break;
		if(i>=inv1[j])
		{
			if(i<=inv2[j]) cnt++;
			else
			{
				j++;
				i--;
				continue;
			}
		}
	}
	cout<<cnt<<"\n";
}
int main()
{
	ll n;cin>>n;
	while(n--) solve();
}