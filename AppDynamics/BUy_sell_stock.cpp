/* Sell and Buy  stocks at most k times
  Written By:Ankush Mitra
  Date:5.1.20 TIme:22.38*/
  int maxProfit(int price[], int n, int k)
  {
  	 int dp[k+1][n+1];
    for(int i=0;i<=k;i++)
       dp[i][0]=0;
    for(int i=0;i<=n;i++)
      dp[0][i]=0;
    for(int i=1;i<=k;i++)
    {
      for(int j=1;j<=n;j++)
      {
  		int mx=0;
        for(int m=0;m<j;m++)
        {
          mx=max(mx,price[j]-price[m]+dp[i-1][m]);
                 }
                 dp[i][j]=max(mx,dp[i][j-1]);
                 }
                 }
                 return dp[k][n-1];
  }
