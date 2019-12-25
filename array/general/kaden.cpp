/* Kaden
   Written By:ANkush Mitra
   Date:25.12.19 Time:11.18*/
   int Solution::maxSubArray(const vector<int> &A) {
       int max_ending_here=0;
       int max_so_far=0;
       bool isAllNegative=true;
       for(int i=0;i<A.size();i++)
       {
           if(A[i]>=0) isAllNegative=false;
           max_ending_here+=A[i];
           if(max_ending_here<0)
             max_ending_here=0;
           if(max_so_far<max_ending_here)
           {
               max_so_far=max_ending_here;
           }
       }
       if(isAllNegative) {
           int maxi=INT_MIN;
           for(int i=0;i<A.size();i++)
           {
               maxi=max(maxi,A[i]);
           }
           return maxi;
       }
       else
       return max_so_far;
   }
