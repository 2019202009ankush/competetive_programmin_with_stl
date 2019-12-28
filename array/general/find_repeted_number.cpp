/* Find out the repeted number
   Written By:Ankush Mitra
   Date:25.12.19 Time:22/41*/
   int Solution::repeatedNumber(const vector<int> &A) {
     int mini=INT_MAX;
     int maxi=INT_MIN;
     for(int i=0;i<A.size();i++)
     {
         mini=min(mini,A[i]);
         maxi=max(maxi,A[i]);
     }
     int allXor=0;
     for(int i=mini;i<=maxi;i++)
     {
         allXor=allXor^i;
     }
     int allElementXor=0;
     for(int i=0;i<A.size();i++)
     {
         allElementXor=allElementXor^A[i];
     }
     return allXor^allElementXor  ;
 }
