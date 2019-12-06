/*Goldmine Problem
  Written By: Ankush Mitra
  Date:6.12.19 Time:21:56*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gold_val(ll **gold,ll m,ll n)
{
  ll goldtable[m][n]={0};
  for(ll j=n-1;j>=0;j--)
  {
    for(ll i=0;i<m;i++)
    {
      ll r=(j==n-1)?0:goldtable[i][j+1];
      ll ru=(j==n-1||i==0)?0:goldtable[i-1][j+1];
      ll rd=(j==n-1||i==m-1)?0:goldtable[i+1][j+1];
      goldtable[i][j]=gold[i][j]+max(max(r,ru),rd);
    }
  }
  ll res=INT_MIN;
  for(int i=0;i<m;i++)
  {

    for(int j=0;j<n;j++)
    {
      // cout<<goldtable[i][j]<<" ";
      res=max(res,goldtable[i][j]);
    }
    cout<<endl;
  }
  return res;
}
int main()
{
   ll m,n;
   cin>>m>>n;
   ll **gold=new ll*[m];
   for(ll i=0;i<m;i++)
   {
     gold[i]=new ll[n];
   }
   for(ll i=0;i<m;i++)
   {
     for(ll j=0;j<n;j++)
     {
       cin>>gold[i][j];
     }
   }
   ll gv=gold_val(gold,m,n);
   cout<<gv;
}
