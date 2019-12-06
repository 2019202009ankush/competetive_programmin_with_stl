/* Find out maximum profit in 0/1 knapsack
   written by:ankush mitra
   Date:6.12.19 Time:23:27*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll max_profit(ll * weights,ll * profits,ll n,ll W)
{
  ll dp[n+1][W+1];
  for(ll i=0;i<=n;i++)
  {
    for(ll j=0;j<=W;j++)
    {
     if(i==0||j==0)
      dp[i][j]=0;
     else
     {
      if(weights[i-1]>j)
        dp[i][j]=dp[i-1][j];
      else
      dp[i][j]=max(dp[i-1][j],profits[i-1]+dp[i-1][j-weights[i-1]]);
     }
    }
  }
  return dp[n][W];
}
int main()
{
 ll n,W;
 cin>>n>>W;
 ll weights[n];
 ll profits[n];
 for(ll i=0;i<n;i++)
 {
 cin>>weights[i];
 }
 for(ll i=0;i<n;i++)
 {
 cin>>profits[i];
 }
 ll w=max_profit(weights,profits,n,W);
 cout<<w<<endl;
}
