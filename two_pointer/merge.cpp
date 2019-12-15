/* Merge two sorted vector
   Written By:Ankush Mitra
   Date:14.12.19 Time:22:38*/
   void merge(vector<int> &A, vector<int> &B) {

       int i=0;
       int j=0;
       int k=0;
       vector<int>c(A.size()+B.size());
       while(i<A.size()&&j<B.size())
       {
           if(A[i]<B[j])
           {
               c[k++]=A[i++];
           }
           else if(B[j]<=A[i])
           {
               c[k++]=B[j++];
           }
       }
       while(i<A.size())
       {
           c[k++]=A[i++];
       }
       while(j<B.size())
       {
           c[k++]=B[j++];
       }
       A.clear();
       for(int i=0;i<c.size();i++)
       {
           A.push_back(c[i]);
       }
   }
