/*find i j k such that max(A[i]-B[j],B[j]-C[k],C[k]-A[i]) is minimizes
  Written by:Ankush Mitra
  Date: 14.12.19 Time:15.01*/
  int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
      int diff=INT_MAX;
      for(int i=0,j=0,k=0;i<A.size()&&j<B.size()&&k<C.size();)
      {
          int mini_1=min(min(A[i],B[j]),C[k]);
          int maxi_1=max(max(A[i],B[j]),C[k]);
          if(diff>abs(maxi_1-mini_1))
          {
              diff=abs(maxi_1-mini_1);
          }
          if(diff==0)
           break;
          if(mini_1==A[i]) i++;
          else if(mini_1==B[j]) j++;
          else k++;
      }
      return diff;
  }
