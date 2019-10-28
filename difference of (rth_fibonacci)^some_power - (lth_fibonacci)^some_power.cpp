/* Code for finding the difference of (rth_fibonacci)^some_power - (lth_fibonacci)^some_power
   it usage divide and concoure to calculate fastExponentation and DP to store all fibonacci number
   Written by : Ankush Mitra 
   Date : 28.10.19 Time : 18.52 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
ll fib[1000009];
ll fastExp(ll base,ll exp)
{
    ll result=1;
    while(exp>0)
    {
        if(exp%2==1) result=((result%mod)*(base%mod))%mod;
        base=((base%mod)*(base%mod))%mod;
        exp=exp/2;
    }
    return result%mod;
}
void fibMake()
{
    fib[0]=0;
    fib[1]=1;
    for(ll i=2;i<1000009;i++)
    {
        fib[i]=(((fib[i-1]%mod)+(fib[i-2]%mod))%mod)%mod;
    }
    
}
int main()
{
    ll power;
    ll q;
    fibMake();
    cin>>power>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        ll result=fastExp(fib[r],power)%mod;
        result=((result%mod)-(fastExp(fib[l],power)%mod))%mod;
        if(result<0)
            result=result+mod;
        cout<<result<<endl;
    }
}