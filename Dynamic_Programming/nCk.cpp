/*Find nCk
  Written By: Ankush Mitra
  Date: 6.12.19 Time: 20:15*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll nCk(ll n,ll k)
{
  ll dp[n+1][n+1];

  for(ll i=0;i<=n;i++)
  {
    for(ll j=0;j<=k;j++)
    {
      if(j==0||j==i)
      {
        dp[i][j]=1;
      }
      else
      {
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
      }
    }

  }

  return dp[n][k];
}
int main()
{
  ll n,k;
  cin>>n>>k;
  ll nck=nCk(n,k);
  cout<<nck<<endl;

}
