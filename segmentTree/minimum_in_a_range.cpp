#include <bits/stdc++.h>
using namespace std;
int seg[4000000];
void build(int* arr,int l,int r,int tree)
{
  if(l==r)
  {
    seg[tree] = arr[l];
      return ;
  }
    int mid = (l+r)/2;
    build(arr,l,mid,2*tree+1);
    build(arr,mid+1,r,2*tree+2);
    seg[tree] = min(seg[2*tree+1],seg[2*tree+2]);
    
}
void update(int * arr,int l,int r,int tree,int idx,int value)
{
    if(l==r)
    {
         arr[l] = value;
         seg[tree] = arr[l];
     return;
    }
    int mid = (l+r)/2;
    if(idx<=mid)
    {
       update(arr,l,mid,2*tree+1,idx,value);
    }
    else
    {
        update(arr,mid+1,r,2*tree+2,idx,value);
    }
    seg[tree] = min(seg[2*tree+1],seg[2*tree+2]);
    
}
int query(int l , int r,int left,int right,int tree)
{
  // cout<<l<<" "<<r<<"  "<<left<<"  "<<right<<"  "<<tree<<endl;
  if(left<=l&&r<=right)  return seg[tree];
  if(l>right||r<left)  return INT_MAX;
  int mid = (l+r) /2;
  int ans1 = query(l,mid,left,right,2*tree+1);
  int ans2 = query(mid+1,r,left,right,2*tree+2);
  return min(ans1,ans2);
}
int main() {

	// Write your code here
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int i=0;
    int j=n-1;
    build(arr,0,n-1,0);
    
    for(int i=0;i<m;i++)
    {
        char q;
        cin>>q;
        if(q=='q')
        {
          int l,r;
          cin>>l>>r;
            l--;
            r--;
           cout<<query(0,n-1,l,r,0)<<endl;
        }
        else
        {
           int  l;
            int r;
            cin>>l>>r;
            l--;
            update(arr,0,n-1,0,l,r);
        }
    }
    
    
}