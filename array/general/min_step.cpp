/* Find out min step in coordiante pair
   Written By:Ankush Mitra
   Date:25.12.19 Time:10:59*/
   int Solution::coverPoints(vector<int> &A, vector<int> &B) {
       int count=0;
       for(int i=1;i<A.size();i++)
       {
           count+=(max(abs(A[i]-A[i-1]),abs(B[i]-B[i-1])));
       }
       return count;
   }
