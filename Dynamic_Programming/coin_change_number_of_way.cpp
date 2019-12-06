/* Coin Change total number of ways to change for a total
  writtn by:ankush Mitra
  Date:6.12.19 Time:22:42*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ways(ll *coins,ll n,ll t,ll **dp)
{

  if(t<0)
    return 0;
  if(t==0)
    return 1;

  if(n<=0)
    return 0;
  if(dp[n][t]>-1)
    return dp[n][t];

  else
  {
    ll option1=ways(coins+1,n-1,t,dp);
    ll option2=ways(coins,n,t-coins[0],dp);
    ll total=option1+option2;
    dp[n][t]=total;
    return total;
  }
    return dp[n][t];

}
int main()
{
  ll coin,t;
  cin>>coin>>t;
  ll *coins=new ll[coin];
  for(ll i=0;i<coin;i++)
  {
  cin>>coins[i];
  }
  ll **dp=new ll*[coin+1];
  for(ll i=0;i<=coin;i++)
  {
   dp[i]=new ll[t+1];
 }
 for(ll i=0;i<=coin;i++)
 {
 for(ll j=0;j<=t;j++)
 {
   dp[i][j]=-1;
 }
 }
  ll way=ways(coins,coin,t,dp);
  cout<<way<<endl;
}
