/* Weighted job scheduling in nlogn
  Written By:Ankush Mitra
  Date:3.1.20 TIme:23.08*/
#include<bits/stdc++.h>
using namespace std;
typedef struct job { 
  int s;
  int e;
  int p;
  job()
  {
    s=0;
    e=0;
    p=0;
  }
  job(int s,int e,int p)
  {
      s=s;
      e=e;
      p=p;
  }
  
}job;
bool comp(struct job a ,struct job b)
{
    return a.e<b.e;
}
int main()
{
    //Write your code here
    int n;
    cin>>n;
    job arr[n];
    for(int i=0;i<n;i++)
    {
        int s,e,p;
        cin>>s>>e>>p;
        arr[i].s = s;
        arr[i].e =e;
        arr[i].p =p;
    }
    sort(arr,arr+n,comp);
    vector<int> endtime,dp;
    for(int i=0;i<n;i++)
    {
      // cout<<arr[i].s<<"  "<<arr[i].e<<"  "<<arr[i].p<<endl;
      endtime.push_back(arr[i].e);
      dp.push_back(arr[i].p);
    }
    for(int i=1;i<n;i++)
    {
      int st = arr[i].s;
      auto it = upper_bound(endtime.begin(),endtime.begin()+i,st);
      if(it==endtime.begin()+i)
      {
         int idx = i-1;
         dp[i]=max(dp[i-1],dp[idx]+arr[i].p);
      }
      else if(it==endtime.begin())
      {
          dp[i]=max(dp[i-1],dp[i]);
      }
      else
      {
         int idx = it - endtime.begin();
         idx --;
         dp[i]=max(dp[i-1],dp[idx]+arr[i].p);
      }
    }
  
    cout<<dp[n-1]<<endl;
    
    return 0;
}