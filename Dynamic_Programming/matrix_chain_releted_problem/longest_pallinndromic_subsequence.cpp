/*Longst Pallindromic Subsquence
  Written By: Ankush Mitra
  Date: 10.12.19 Time: 15.30*/
#include<bits/stdc++.h>
using namespace std;
int length(string s)
{
  int n=s.size();
  int dp[n][n];
  for(int i=0;i<n;i++)
  {
    dp[i][i]=1;
  }
  for(int L=2;L<=n;L++)
  {
   for(int i=0;i<n-L+1;i++)
   {
    int j=i+L-1;
    if(L==2&&s[i]==s[j])
     dp[i][j]=2;
    else if(s[i]==s[j])
     dp[i][j]=2+dp[i+1][j-1];
     else
     {
       dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
     }
   }
  }
  return dp[0][n-1];
}
int main()
{
 string s;
 cin>>s;
 cout<<length(s);
}
