/* Longest Common Subsequence Printing it
   Written By: Ankush Mitra
   Date:10.12.19 Time:17:36*/
#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b)
{
  int m=a.size();
  int n=b.size();
  int dp[m+1][n+1];
  for(int i=0;i<=m;i++)
  {
  for(int j=0;j<=n;j++)
  {
    if(i==0||j==0)
    {
     dp[i][j]=0;
    }
    else
    {
      if(a[i-1]==b[j-1])
      {
        dp[i][j]=1+dp[i-1][j-1];
      }
      else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  }
  int index=dp[m][n];
  char LCS[index+1];
  LCS[index]='\0';
  int i=m;
  int j=n;
  while(i>0&&j>0)
  {
   if(a[i-1]==b[j-1])
   {
    LCS[index-1]=a[i-1];
    i--;
    j--;
    index--;
   }
   else
   {
    if(dp[i-1][j]>dp[i][j-1])
    {
      i--;
    }
    else
    {
     j--;
    }
   }
  }
  cout<<"Longest Common Substring is ";
  printf("%s",LCS);
  cout<<endl;
  return dp[m][n];
}
int main()
{
  string a,b;
  cin>>a>>b;
  cout<<lcs(a,b);
}
