/*Find nPk
  Written By: Ankush Mitra
  Date: 6.12.19 Time: 20:15*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll nPk(ll n,ll k)
{
  ll dp[n+1][k+1];

  for(ll i=0;i<=n;i++)
  {
    for(ll j=0;j<=min(k,i);j++)
    {
      if(j==0)
      {
        dp[i][j]=1;
      }
      else
      {
        dp[i][j]=j*dp[i-1][j-1]+dp[i-1][j];
      }
      dp[i][j+1]=0;
    }

  }

  return dp[n][k];
}
int main()
{
  ll n,k;
  cin>>n>>k;
  ll npk=nPk(n,k);
  cout<<npk<<endl;

}
