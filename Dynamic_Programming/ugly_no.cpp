/* Find Ugly Numner in O(n)
   Written By:Anskush Mitra
   Date:6.12.19 Time:19:28 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
   ll n;
   cin>>n;
   ll dp[n],i2=0,i3=0,i5=0;
   dp[0]=1;
   ll nex_two_mul=2;
   ll nex_three_mul=3;
   ll nex_five_mul=5;
   for(ll i=1;i<n;i++)
   {
     ll mini=min(min(nex_two_mul,nex_three_mul),nex_five_mul);
     dp[i]=mini;
     if(mini==nex_two_mul)
     {
       i2+=1;
       nex_two_mul=dp[i2]*2;
     }
     if(mini==nex_three_mul)
     {
       i3+=1;
       nex_three_mul=dp[i3]*3;
     }
     if(mini==nex_five_mul)
     {
       i5+=1;
       nex_five_mul=dp[i5]*5;
     }
   }
   for(int i=0;i<n;i++)
   cout<<dp[i]<<" ";
}
