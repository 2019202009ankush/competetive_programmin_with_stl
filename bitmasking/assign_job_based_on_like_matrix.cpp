typedef long long int ll;
ll ways(int like[][MAXN],int N,ll per,vector<ll>&dp,ll mask)
{ 
   // cout<<"in 4"<<dp[mask]<<" "<<per<<endl;
    if(mask==(1<<N)-1) return 1;
    else
    {
        if(dp[mask]!=0) return dp[mask];
        else
        {
           
           for(ll i=0;i<N;i++)
           {
               // cout<<like[per][i]<<"  "<<(mask&(1<<i))<<endl;
               if(like[per][i]==1&&((mask&(1<<i))==0))
               {
                    // cout<<"in line11"<<dp[mask]<<" "<<per<<endl;
                 dp[mask]+= ways(like,N,per+1,dp,mask|(1<<i));
               }
           }
        }
        return dp[mask];
    }
}
long long solve(int like[][MAXN],int N)
{
	// Write your code here.
    vector<ll> dp(1<<MAXN,0);
    ll mask =0 ;
    return ways(like,N,0,dp,mask);
}
