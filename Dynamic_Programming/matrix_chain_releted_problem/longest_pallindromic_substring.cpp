/*Longst Pallindromic Substring
  Written By: Ankush Mitra
  Date: 10.12.19 Time: 16.46*/
#include<bits/stdc++.h>
using namespace std;
int length(string s)
{
  int n=s.size();
  bool dp[n][n];
  int maxLength=1; int start=-1;
  for(int i=0;i<n;i++)
  {
    dp[i][i]=1;
  }
  for(int i=0;i<n-1;i++)
  {
    if(s[i]==s[i+1])
    {
     dp[i][i+1]=1;
     start=i;
     maxLength=2;
    }
  }
  for(int L=3;L<=n;L++){
   for(int i=0;i<n-L+1;i++)
   {
    int j=i+L-1;
    if(s[i]==s[j]&&dp[i+1][j-1])
    {
      dp[i][j]=1;
      if(maxLength<L){
          start=i;
          maxLength=L;
      }

    }
  }
  }
  return maxLength;
}
int main()
{
 string s;
 cin>>s;
 cout<<length(s);
}
