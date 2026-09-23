#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c; cin>>a>>b>>c;
	long long c2=a.size()-1;
	long long c1=b.size()-1;
	if(a[c2-1]+a[c2]==b[0]+b[1] and b[c1-1]+b[c1]==c[0]+c[1]){
		cout<<"Yes";
	}
	else cout<<"No";
}