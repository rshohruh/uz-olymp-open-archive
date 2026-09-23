#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	reverse(a.begin(), a.end());
	if (a[0]!=b[0]) {
	cout<<"No";
	return 0; }
	else {
	reverse(b.begin(), b.end());
	if (b[0]==c[0])
	cout<<"Yes";
	else
	cout<<"No"; }
    
}