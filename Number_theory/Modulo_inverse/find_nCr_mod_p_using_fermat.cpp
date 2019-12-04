#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
ll f[1000009];
ll fast(ll base,ll exp)
{
  ll res=1;
 while(exp>0)
 {
     if(exp%2==1) res=(res%mod * base%mod +mod )%mod;
      base=((base%mod)*(base%mod) +mod )%mod;
     exp/=2;
 }
 return res%mod;
}
int main(){
    f[0]=1;
    for(int i=1;i<=1e6+8;i++)
    {
        f[i]=((i%mod)*(f[i-1]%mod))%mod;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,r;
        cin>>n>>r;
        ll ans=f[n]%mod;
        ans=((ans%mod)*(fast(f[r],mod-2)%mod))%mod;
        ans=((ans%mod)*(fast(f[n-r],mod-2))%mod)%mod;
        cout<<ans<<endl;
    }
}
