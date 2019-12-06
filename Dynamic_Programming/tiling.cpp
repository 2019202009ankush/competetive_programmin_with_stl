/* Tiling with Dominoes
  Given a 2*n board and tiles of size 2*1 count number of ways to tile the given board using the 2*1 tiles.A tile can be either be placed horizontial or vertically
  Written By: Ankush Mitra
  Date:6.12.19 Time:21:39*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  ll n;
  cin>>n;
  //cn=cn-1+cn-2
  ll dp[n+1];
  dp[1]=1;
  dp[2]=2;
  for(ll i=3;i<=n;i++)
  {
  dp[i]=dp[i-1]+dp[i-2];
  }
  cout<<dp[n]<<endl;
}
