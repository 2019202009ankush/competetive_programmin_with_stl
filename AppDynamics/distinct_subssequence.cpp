/* count distinct subsequence of a array
   Written By:Ankush Mitra
  Date:5.1.20 TIme:20.42*/
  int countSub(string str)
  {

    vector<int> last(MAX_CHAR,-1);
    int n=str.size();
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
      dp[i]=2*dp[i-1];
      if(last[str[i-1]]!=-1)
      {
  		dp[i]=dp[i]-dp[last[str[i-1]]];

      }
      last[str[i-1]]=i-1;

    }
    return dp[n];

  } 
