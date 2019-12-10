/* Longest Pallindromic Subsquence top down
  Written By: Ankush Mitra
  Date:10.12.19 Time: 16.10*/
#include<bits/stdc++.h>
using namespace std;
int lps(string s,int i,int j,int ** dp)
{
  if(i==j) return 1;
  if(s[i]==s[j]&&i+1==j) return 2;
  if(dp[i][j]>-1) return dp[i][j];
  else
  {
    if(s[i]==s[j])
    {
      int ans=lps(s,i+1,j-1,dp);
      dp[i][j]=2+ans;
      return dp[i][j];
    }
    else
    {
      int option1=lps(s,i,j-1,dp);
      int option2=lps(s,i+1,j,dp);
      dp[i][j]=max(option1,option2);
      return dp[i][j];
    }
  }
}
int main(){
  string s;
  cin>>s;
  int size=s.size();
  int ** dp=new int*[size];
  for(int i=0;i<size;i++)
 {
   dp[i]=new int[size];
 }
 for(int i=0;i<size;i++)
 {
   for(int j=0;j<size;j++)
   {
     dp[i][j]=-1;
   }
 }
 cout<<lps(s,0,size-1,dp);
}
