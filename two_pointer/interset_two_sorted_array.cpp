/* Intersect of two sorted array
   Written By:Ankush Mitra
   Date:14.12.19 Time:17:53*/
   vector<int>intersect(const vector<int> &A, const vector<int> &B) {
     int i=0;
     int j=0;
     vector<int> Q;
     while(i<A.size()&&j<B.size())
     {
         if(A[i]==B[j])
         {
             Q.push_back(A[i]);
             i++;
             j++;
         }
         else if(A[i]<B[j])
         {
             i++;
         }
         else{
             j++;
         }
     }
     return Q;
   }
