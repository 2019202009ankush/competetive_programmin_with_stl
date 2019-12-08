/* Magical grid problem codezen
   Written By:Ankush Mitra
   Date:7.12.19 Time:21:07*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int arr[r][c];
        int dp[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                dp[i][j]=0;
                cin>>arr[i][j];
            }
        }
        dp[r-1][c-1]=1;
        dp[r-1][c-2]=1;
        dp[r-2][c-1]=1;
        for(int i=c-2;i>=0;i--)
        {
            dp[r-1][i]=dp[r-1][i+1]-(arr[r-1][i+1])<1?1:dp[r-1][i+1]-(arr[r-1][i+1]);
        }
         for(int i=r-2;i>=0;i--)
        {
            dp[i][c-1]=dp[i+1][c-1]-(arr[i+1][c-1])<1?1:dp[i+1][c-1]-(arr[i+1][c-1]);
        }
        for(int i=r-2;i>=0;i--)
        {
            for(int j=c-2;j>=0;j--)
            {
                dp[i][j]=min(dp[i][j+1]-arr[i][j+1],dp[i+1][j]-arr[i+1][j]);
                if(dp[i][j]<1)
                {
                    dp[i][j]=1;
                }
            }
        }
        cout<<dp[0][0]<<endl;
    }
    return 0;
}
