/* Find out is subset sum possible
   written by:ankush mitra
   Date:6.12.19 Time:23:27*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool subset_sum(ll * nums,ll n,ll W)
{
  bool dp[n+1][W+1];
  for(ll i=0;i<=n;i++)
  {
    for(ll j=0;j<=W;j++)
    {
     if(j==0)
       dp[i][j]=true;
    else if(i==0&&j==0)
      dp[i][j]=true;
    else if(i==0&&j!=0)
      dp[i][j]=false;
     else
     {
      if(nums[i-1]>j)
        dp[i][j]=dp[i-1][j];
      else
      dp[i][j]=(dp[i-1][j])||(dp[i-1][j-nums[i-1]]);
     }
    }
  }
  return dp[n][W];
}
int main()
{
 ll n,W;
 cin>>n>>W;

 ll nums[n];
 for(ll i=0;i<n;i++)
 {
 cin>>nums[i];
 }
 bool w=subset_sum(nums,n,W);
 cout<<w<<endl;
}
