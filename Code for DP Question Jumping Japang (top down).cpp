/* Code for DP Question Jumping Japang (top down)
   Problem is form any point you can go x->x+1 with cost a or x->3*x with cost b now find minimum cost
   required to read destination from 1
   Written By : Ankush Mitra
   Date : 28.10.19 Time : 20.07 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll END;
ll FindCost(ll start,ll a,ll b,vector<ll> &dp)
{
   if(start>END)
     return INT_MAX;
   else{
       if(start==END) return 0;
       if(dp[start]==-1)
       {
           dp[start]=min(FindCost(start+1,a,b,dp)+a,FindCost(start*3,a,b,dp)+b);
       }
       return dp[start];
   }
}
int main() {
    ll n,a,b;
    cin>>n>>a>>b;
    END=n;
    vector<ll> dp(n+1,-1);
    cout<<FindCost(1,a,b,dp)<<endl;
    return 0;
}

