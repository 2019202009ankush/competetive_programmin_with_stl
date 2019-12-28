/* Find next permutation
  Wriiten By:Ankush Mitra
  Date:25.12.19 Time:22.28*/
  vector<int> Solution::nextPermutation(vector<int> &A) {
      int i;
      for(i=A.size()-1;i>0;i--)
      {
          if(A[i]>A[i-1]) break;
      }
      if(i==0) {
          reverse(A.begin(),A.end());
          return A;
      }
      else{
          int idx=i;
          int j;
          for(int j=i;j<A.size();j++)
          {
              if(A[j]>A[i-1]) {
                  idx=j;
              }
          }
          int temp=A[i-1];
          A[i-1]=A[idx];
          A[idx]=temp;
          sort(A.begin()+i,A.end());
          return A;
      }
  }
