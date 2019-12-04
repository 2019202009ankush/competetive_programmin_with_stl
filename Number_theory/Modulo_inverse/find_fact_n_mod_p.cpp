#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll fastexp(ll base,ll exp,ll mod)
{
    ll res=1;
    while(exp>0)
    {
        if(exp%2==1)
        {
            res=((res%mod)*(base%mod)+mod)%mod;
        }
        base=((base%mod)*(base%mod)+mod)%mod;
        exp=exp/2;
    }
    return res%mod;
}

int main() {

	// Write your code here
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p;
       
        cin>>n>>p;
        if(n>=p) cout<<"0"<<endl;
        else
        {
            ll ans=1;   
            for(int i=n+1;i<=p-1;i++)
            {
                ans=((ans%p)*(fastexp(i,p-2,p)%p)+p)%p;
            }
            cout<<-ans+p<<endl;
    }
        }
        
}