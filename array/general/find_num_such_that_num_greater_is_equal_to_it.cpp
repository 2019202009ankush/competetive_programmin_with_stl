/* Find if there exits any number such that number of num greater than that is equal to that
   Written BY:Ankush Mitra
   Date:29.12.19 Time:21.18*/


   int Solution::solve(vector &A) {
   sort(A.begin(),A.end());
   if(A[A.size()-1]==0)
   return 1;
   for(int i=0;i<A.size()-1;i++){
   if(A[i]==((A.size()-1)-i)&&A[i]!=A[i+1])
   return 1;}
   return -1;
   }
