/*Matrix chain using bottom up
 Written By:Ankush Mitra
 Date:10.12.19 Time:14.42*/
#include<bits/stdc++.h>
using namespace std;
int ways(int *arr,int n)
{
  int dp[n][n];
  for(int i=1;i<n;i++)
  {
    dp[i][i]=0;
  }
  for(int L=2;L<n;L++)
  {
    for(int i=1;i<n-L+1;i++)
    {
      int j=i+L-1;
      dp[i][j]=INT_MAX;
      for(int k=i;k<j;k++)
      {
        int total_cost=(dp[i][k]+dp[k+1][j])+(arr[i-1]*arr[k]*arr[j]);
        dp[i][j]=min(dp[i][j],total_cost);
      }
    }
  }
  return dp[1][n-1];
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
  cout<<ways(arr,n);

}
