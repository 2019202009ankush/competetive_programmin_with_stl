/* Maximum Product subarray
  Written By:Ankush mitra
  Date:12.12.19 Time: 15:56*/
#include<bits/stdc++.h>
using namespace std;
int max_product_subarray(int *arr,int n)
{
 int max_so_far=1;
 int max_ending_here=1;//can be 1 or >1
 int min_ending_here=1;//can be 1 or <1
 int isAllNegative=true;
 for(int i=0;i<n;i++)
 {
   if(arr[i]>0)
   {
      max_ending_here=max_ending_here*arr[i];//assume I have max value
      min_ending_here=min(min_ending_here*arr[i],1);//assume I have already a min negative but min_ending_here can be 1
      isAllNegative=false;
   }
   else if(arr[i]==0)
   {
    max_ending_here=1;
    min_ending_here=1;
   }
   else{
        int temp=max_ending_here;
        max_ending_here=max(min_ending_here*arr[i],1);//because min_ending_here can be 1
        min_ending_here=temp*arr[i];
   }
   if(max_so_far<max_ending_here)
   {
      max_so_far=max_ending_here;
   }

 }
 if(isAllNegative&&max_so_far==1)//max_so_far is 0 if all number <= 0
 {
   int all1=1;// all can be -1 making a postive 1
   int maxi=INT_MIN;
   for(int i=0;i<n;i++)
   {
       all1*=arr[i];
       maxi=max(maxi,(arr[i]));
   }
  return all1==1?1:maxi;//if all negative Then return Maximum negative else all -1 can make a 1 so return that
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
