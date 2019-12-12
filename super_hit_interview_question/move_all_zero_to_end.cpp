/* Move all zero to the end
  Written By: Ankush Mitra
  Date:12.12.19 Time:15:25*/
#include<bits/stdc++.h>
using namespace std;
void moveZero(int *arr,int n)
{
   int left=-1;
   for(int i=0;i<n;i++)
   {
     if(arr[i]!=0)
     {
      arr[++left]=arr[i];
     }
   }
   while(left<n)
   {
     arr[++left]=0;
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
   moveZero(arr,n);
   for(int i=0;i<n;i++)
   {
     cout<<arr[i]<<" ";
   }
}
