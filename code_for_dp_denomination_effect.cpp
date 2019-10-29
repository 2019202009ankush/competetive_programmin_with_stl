/* Code for Denomination effect
   Written By: Ankush Mitra
   Date : 29.10.19 Time : 17.17*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   int max_ele=INT_MIN;
   cin>>n;
    vector<int> arr;
   for(int i=0;i<n;i++)
   {
       int m;
       cin>>m;
       arr.push_back(m);
       max_ele=max(max_ele,m);
   }
   vector<int>dp(1e6+1,INT_MAX);
    dp[0]=0;
   for(int i=1;i<=1e6;i++)
   {
       for(int j=0;j<arr.size();j++)
       {
            if(arr[j]<=i)
            {
                int tem=dp[i-arr[j]];
                if(tem!=INT_MAX&&dp[i]>dp[i-arr[j]]+1)
                    dp[i]=dp[i-arr[j]]+1;
            }
       }
   }
    for(int i=max_ele;i<=1e6;i++)
    {
        if(dp[i]>=INT_MAX)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"Fake Offer!"<<endl;
    return 0;
    
}