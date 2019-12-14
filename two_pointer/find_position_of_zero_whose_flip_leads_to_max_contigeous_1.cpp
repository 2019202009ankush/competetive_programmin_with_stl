/* Find out position of zero flip of which will lead to max sequence of 1
   WritteN By:Ankush Mitra
   Date:14/12/19 Time:18.30*/
#include<bits/stdc++.h>
using namespace std;
vector<int>maxone(vector<int> &A) {
 int max_length=0;
 int max_left=-1;
 int max_right=-1;
 for(int i=0;i<A.size();i++)
 {
     //odd length
     if(A[i]==0)
     {
         int l=i-1;
         int r=i+1;
          while(l>=0&&r<A.size())
          {
            if(A[l]==1&&A[r]==1)
            {
                l--;
                r++;
            }
            else if(A[l]==1&&A[r]==0)
            {
                l--;
            }
            else if(A[r]==1&&A[l]==0)
            {
                r++;
            }
            else
            {
                break;
            }
            int curr_length=(r-l+1);
            if(max_length<curr_length)
            {
                max_length=curr_length;
                max_left=l;
                max_right=r;
            }
          }
     }

 }
 vector<int>Q;
 if(max_left==-1)
 {
     Q.push_back(0);
     return Q;
 }
 for(int i=max_left;i<=max_right;i++)
 {
    Q.push_back(i);
 }
 return Q;
}
int main()
{
 int n=4,temp;

 vector<int>A,Q;
 A.push_back(0);
 for(int i=1;i<n;i++)
 {
   temp=1;
   A.push_back(temp);
 }
 Q=maxone(A);
 for(int i=0;i<Q.size();i++)
 {
   cout<<Q[i]<<" ";
 }

}
