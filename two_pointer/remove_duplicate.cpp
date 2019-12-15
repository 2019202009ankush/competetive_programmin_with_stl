/* Remove Duplicate From Sorted Array
  Written By:Ankush Mitra
  Date:14.12.19 Time:23.05*/
  int removeDuplicates(vector<int> &A) {
      int left=0;
      for(int i=1;i<A.size();i++)
      {
          if(A[i]!=A[i-1])
          {
              left++;
              A[left]=A[i];
          }
      }
      return left+1;
  }
