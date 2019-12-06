/* Friend pair given n friend find how many ways they pair
   F(n)=F(n-1)+(n-1)*(F(n-2))
   Written By:ankush mitra
   Date:6.12.19 Time:23:15*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  ll n;
  cin>>n;
  ll dp[n+1];
   dp[1]=1;
   dp[2]=2;
  for(ll i=3;i<=n;i++)
  {
    dp[i]=dp[i-1]+(i-1)*dp[i-2];
  }
  cout<<dp[n]<<endl;
}
