#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
	ll n;cin>>n;
	ll a=n/28;
	ll b=n/7-a;
	ll c=n/4-a;
	cout<<c<<" "<<b<<" "<<a;
}