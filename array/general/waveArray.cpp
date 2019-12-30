/* Wave array
   Written By:Ankush Mitra
   Date:29.12.19 Time:22.09*/
   vector<int> Solution::wave(vector<int> &A) {

     for(int i=0;i<A.size();i+=2)
     {
         if(i-1>0&&A[i-1]>A[i])
         {
             int temp=A[i-1];
             A[i-1]=A[i];
             A[i]=temp;
         }
         if(i+1<A.size()&&A[i]<A[i+1])
         {
             int temp=A[i+1];
             A[i+1]=A[i];
             A[i]=temp;
         }
     }
     return A;
 }
