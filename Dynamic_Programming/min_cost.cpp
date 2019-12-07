/* Mini Cost Path
  Written By: Ankush Mitra
  Date:7.12.19 Time:18:28*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll min_cost(ll **cost,ll m,ll n,ll i,ll j,ll **dp)
{
  if(i==m&&j==n)
    return cost[m][n];
  if(i>m||j>n)
    return INT_MAX;
  cout<<i<<" "<<j<<endl;

  if(dp[i][j]!=-1)
    return dp[i][j];

  else
  {
    ll option1=min_cost(cost,m,n,i+1,j,dp);
    ll option2=min_cost(cost,m,n,i+1,j+1,dp);
    ll option3=min_cost(cost,m,n,i,j+1,dp);
    dp[i][j]=cost[i][j]+min(option1,min(option2,option3));
    return dp[i][j];
  }

}
ll mini_cost_iterative(ll **cost,ll m,ll n)
{
    ll dp[m][n];
    dp[m-1][n-1]=cost[m-1][n-1];

    for(ll i=m-2;i>=0;i--)
    {
      dp[i][n-1]=dp[i+1][n-1]+cost[i][n-1];
    }
    for(ll i=n-2;i>=0;i--)
    {
      dp[m-1][i]=dp[m-1][i+1]+cost[m-1][i];
    }
    for(int j=n-2;j>=0;j--)
    {
      for(int i=m-2;i>=0;i--)
      {
        dp[i][j]=cost[i][j]+min(min(dp[i][j+1],dp[i+1][j]),dp[i+1][j+1]);
      }
    }
    return dp[0][0];
}
int main()
{
  ll m,n;
  cin>>m>>n;
  ll ** cost=new ll*[m];
  for(ll i=0;i<m;i++)
  {
    cost[i]=new ll[n];
  }
  for(ll i=0;i<m;i++)
  {
    for(ll j=0;j<n;j++)
    {
       cin>>cost[i][j];
    }
  }
  ll ** dp=new ll*[m];
  for(ll i=0;i<m;i++)
  {
    dp[i]=new ll[n];
  }
  for(ll i=0;i<m;i++)
  {
    for(ll j=0;j<n;j++)
    {
       dp[i][j]=-1;
    }
  }
  ll ans1=min_cost(cost,m-1,n-1,0,0,dp);
  cout<<ans1<<endl;
  ll ans2=mini_cost_iterative(cost,m,n);
  cout<<ans2<<endl;

}
