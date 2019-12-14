/* find nth element in a unsorted array
   Written By:Ankush Mitra
   Date:14.12.19 Time:12:05*/
#include<bits/stdc++.h>
using namespace std;
int partition(int *arr,int l,int r)
{
  int pivot=arr[r];
  int left=l-1;
  for(int i=l;i<=r-1;i++)
  {
    if(arr[i]<pivot)
    {
      left++;
      int temp=arr[left];
      arr[left]=arr[i];
      arr[i]=temp;
    }

  }
  left++;
  int temp=arr[r];
  arr[r]=arr[left];
  arr[left]=temp;
  return left;
}
int n_th(int *arr ,int l,int r,int k)
{
   if(k>=1&&k<=r-l+1)
   {
     int w=partition(arr,l,r);
     if(k-1==w-l)
     {
       return arr[w];
     }
    else if(w-l>k-1)
    {
      return n_th(arr,l,w-1,k);
    }
    else
    {
    return  n_th(arr,w+1,r,k-w+l-1);
    }
   }
}
int main()
{
  int n,k,t;
  cin>>n>>t;
  int arr[n];
  for(int i=0;i<n;i++)
  {
     cin>>arr[i];
  }
  while(t--)
  {
    cin>>k;
    cout<<n_th(arr,0,n-1,k);
  }
  

}
