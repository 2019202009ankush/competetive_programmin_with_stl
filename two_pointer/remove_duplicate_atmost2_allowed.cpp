/* Remove Duplicate with Atmost two occurence
  WrittenBy:Ankush Mitra
  Date:15.12.19 Time:14.46*/
  int removeDuplicates(vector<int> &A) {
     int left=-1;
     int n=A.size();
     for(int i=0;i<n;i++)//better to go from first to last
     {
         if(i<n-2&&A[i]==A[i+1]&&A[i]==A[i+2])//if i>=n-2 then atmost two never occur
         {
             continue;
         }
         else
         {
             ++left;
             A[left]=A[i];
         }
     }
     return left+1;
  }
