/*Given a set of n elements find number of ways of partitioning it
  Written By: Ankush Mitra
  Date: 6.12.19 Time: 20:15*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll Bell_using_Bell_Triangle(ll n)
{
  ll dp[n+1][n+1];
  dp[0][0]=1;
  /* Bell Triangle:
     1
     1 2
     2 3 5
     5 7 10 15
     */
  for(int i=1;i<=n;i++)
  {
    dp[i][0]=dp[i-1][i-1];
    for(int j=1;j<=i;j++)
    {
      dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
    }
  }
  return dp[n][0];
}
ll Bell_using_S(ll n)
{
  /* S(n+1,k)=kS(n,k)+S(n,k-1)
     Bell=E(S(n,k)) for all k<=n
  */
}
int main()
{
  ll n;
  cin>>n;
  ll bell_nth=Bell_using_Bell_Triangle(n);
  cout<<bell_nth<<endl;

}
