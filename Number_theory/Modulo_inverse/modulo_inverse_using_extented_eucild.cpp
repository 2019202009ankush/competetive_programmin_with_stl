#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b,ll *x,ll *y)
{
	if(a==0)
	{
		*x=0;
		*y=1;
		return b;
	}
	else
	{
		ll x1,y1;
		ll k=gcd(b%a,a,&x1,&y1);
		*x=y1-(b/a) * x1;
		*y=x1;


		return k;

	}
}
int main()
{
	ll a,m,x,y;
	cin>>a>>m;
	ll gcd_=gcd(a,m,&x,&y);
	cout<<gcd_<<" "<<x<<" "<<y<<endl;
	if(gcd_==1)
	{
		cout<<(x%m +m )%m<<endl;
	}
}