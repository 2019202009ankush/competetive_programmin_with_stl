/* Find nth catalayn number using Two method-Dp,Binomial Coefficient works for n<=30
   Remember that when catalayn number is big we have to take its modulo by using Fermat's Theorem
   Wriiten By:Ankush Mitra
   Date:6.12.19 Time:19:37 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll nth_catlan_using_dp(ll n)
{
  ll dp[n+1];
  dp[0]=1;
  dp[1]=1;
  for(ll i=2;i<=n;i++)
  {
    dp[i]=0;
    for(ll j=0;j<i;j++)
    {
      dp[i]+=dp[j]*dp[i-j-1];
    }
  }
  return dp[n];
}
ll Binomial(ll n,ll r)
{
  ll res=1;
  if(r>n-r)
  {
    r=n-r;//(nCr=nCn-r)
  }
  for(int i=0;i<r;i++)
  {
    res*=(n-i);
    res/=(i+1);
  }
  return res;
}
ll nth_catlan_using_binomial_coffe(ll n)
{
  ll cn=Binomial(2*n,n);
  return cn/(n+1);
}
int main()
{
  ll n,cn;
  //cn=sum(ci*c(n-i-1)) for all i<n
  std::cin >> n;
  cn=nth_catlan_using_dp(n);
  cout<<cn<<endl;
  cn=nth_catlan_using_binomial_coffe(n);
  cout<<cn<<endl;
}
