/* Maximum Sum subarray
  Written By:Ankush mitra
  Date:12.12.19 Time: 15:56*/
#include<bits/stdc++.h>
using namespace std;
int max_product_subarray(int *arr,int n)
{
  int max_so_far=0;
  int max_ending_here=0;
  bool isAlllessTHanZero=true;
  for(int i=0;i<n;i++)
  {
    if(arr[i]>0) isAlllessTHanZero=false;
    max_ending_here=max_ending_here+arr[i];
    if(max_ending_here<0)
      max_ending_here=0;
    if(max_so_far<max_ending_here)
      max_so_far=max_ending_here;

  }
  if(isAlllessTHanZero)
  {
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
      maxi=max(maxi,arr[i]);
    }
    return maxi;
  }
  else
  {
    return max_so_far;
  }

}
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
  cin>>arr[i];
}
cout<<max_product_subarray(arr,n)<<endl;
}
