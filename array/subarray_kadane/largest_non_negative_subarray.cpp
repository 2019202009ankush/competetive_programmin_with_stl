/* Largest non negative subarray
  Written By:Ankush Mitra
  Date:12.12.19 Time:16.47*/
#include<bits/stdc++.h>
using namespace std;
int length_of_nonnegative_subarray(int *arr ,int n)
{
 int res=0;
 for(int i=0;i<n;i++)
 {
   int count=0;
   while(i<n&&arr[i]>=0)
   {
      count++;
      i++;
   }
   res=max(res,count);
 }
 return res;
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
 cout<<length_of_nonnegative_subarray(arr,n)<<endl;
}
