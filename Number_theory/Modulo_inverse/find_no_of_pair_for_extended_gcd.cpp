/*FInd how many pair possible for ax+by=d
 Written By:Ankush Mitra
 Date:11.12.19 Time:1:31*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll extented_gcd(ll a,ll b,ll * x, ll *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    else
    {
        ll x1;
        ll y1;
        ll gcd=extented_gcd(b%a,a,&x1,&y1);
        *x=y1-(b/a)*x1;
        *y=x1;
        return gcd;
    }
}
ll mod_inverse(ll a,ll b)
{
    ll x,y;
    if(extented_gcd(a,b,&x,&y)==1)
    {
        return (x%b+ b)%b;
    }
}
int main(){
	// Write your code here
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,d;
        cin>>a>>b>>d;
        ll g=__gcd(a,b);
        if(d%g!=0)
         {
            cout<<"0"<<endl;
            continue;
         }
        else if(d==0)
        {
            cout<<"1"<<endl;
            continue;
        }
        else{
            a=a/g;
            b=b/g;
            d=d/g;
        ll y1=((d%a)*mod_inverse(b,a) +a) % a;
        ll ans=(d/b);
        if(d<b*y1)
        {
            cout<<"0"<<endl;
            continue;
        }

        else
        {
            ans=ans-y1;
            ans=ans/a;
            ans=ans+1;
            cout<<ans<<endl;
        }

    }
    }
	return 0;
}
