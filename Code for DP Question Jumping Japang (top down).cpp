/* Code for DP Question Jumping Japang (top down)
   Problem is form any point you can go x->x+1 with cost a or x->3*x with cost b now find minimum cost
   required to read destination from 1
   Written By : Ankush Mitra
   Date : 28.10.19 Time : 20.07 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll FindCost(int start,int a,int b,int end,int ** dp)
{
    //cout<<start<<" "<<end<<endl;
    if(start>end) return INT_MAX;
    if(start==end) return 0;
    if(dp[start][end]>-1)
        return dp[start][end];
    ll cost1=FindCost(start+1,a,b,end,dp);
    ll cost2=FindCost(start*3,a,b,end,dp);
    cost1=cost1+a;
    cost2=cost2+b;
    //cout<<start<<" "<<end<<" "<<cost1<<" "<<cost2<<endl;
    dp[start][end]=min(cost1,cost2);
    return min(cost1,cost2);
}
int main() {
    ll n,a,b;
    cin>>n>>a>>b;
    int ** dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[n+1];
        memset(dp[i],-1,(n+1)*sizeof(int));
    }
    cout<<FindCost(1,a,b,n,dp);
    return 0;
}
