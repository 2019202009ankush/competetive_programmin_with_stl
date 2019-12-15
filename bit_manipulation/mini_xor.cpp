/* Minimum xor in a array nlogn
   Written By:Ankush Mitra
   Date:15.12.19 Time:17.17*/
   int findMinXor(vector<int> &A) {
       int min_xor=INT_MAX;
       sort(A.begin(),A.end());
       min_xor=A[0]^A[1];
       for(int i=2;i<A.size();i++)
       {
           min_xor=min(min_xor,(A[i]^A[i-1]));
       }
       return min_xor;
   }
