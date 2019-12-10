/*Matrix chain using top down
 Written By:Ankush Mitra
 Date:10.12.19 Time:14.20*/
#include<bits/stdc++.h>
using namespace std;
int ways(int *arr,int i,int j,int ** dp)
{
  if(i==j) return 0;
  if(dp[i][j]>-1)
    return dp[i][j];
  else{
    int mini=INT_MAX;

    for(int k=i;k<j;k++)
    {
      int subproblem1=ways(arr,i,k,dp);
      int subproblem2=ways(arr,k+1,j,dp);
      int final_multiply_cost=(arr[i-1]*arr[k]*arr[j]);
      int total_cost=subproblem1+subproblem2+final_multiply_cost;
      mini=min(mini,total_cost);
    }
    dp[i][j]=mini;
    return dp[i][j];
  }
  }

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int ** dp = new int * [n];
  for(int i=0;i<n;i++)
  {
    dp[i]=new int[n];
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      dp[i][j]=-1;
    }
  }
  cout<<ways(arr,1,n-1,dp);

}
