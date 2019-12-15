/* Remove all instance of a particular value
  Written By:Ankush Mitra
  Date:15.12.19 Time:14.52*/
  int removeElement(vector<int> &A, int B) {
      int left=-1;
      for(int i=0;i<A.size();i++)
      {
          if(A[i]!=B)
          {
              left++;
              A[left]=A[i];
          }
      }
      return left+1;
  }
