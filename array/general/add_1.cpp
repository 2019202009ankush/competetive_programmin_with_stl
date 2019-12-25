/* Add 1 to array
  Written BY:Ankush Mitra
  Date:25.12.19 Time:11.10*/
  vector<int> Solution::plusOne(vector<int> &A) {
      int t;
      int carry=0;

      for(int i=A.size()-1;i>=0;i--)
      {
          if(i==A.size()-1)
          t=A[i]+1;
          else
          t=A[i];
          A[i]=(carry+t)%10;
          carry=(carry+t)/10;
      }
      if(carry)
      {
          A.insert(A.begin(),carry);
      }
      int i;
      for( i=0;i<A.size();i++)
      {
          if(A[i]!=0) break;
      }
      return vector<int>(A.begin()+i,A.end());
  }
