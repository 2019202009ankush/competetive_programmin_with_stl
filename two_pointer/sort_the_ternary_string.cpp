/* sort the 0 1 2 without using sort() and in order of n
   Written By:Ankush Mitra
  Date:15.12.19 Time:15.03*/
 void sortColors(vector<int> &A) {
     int count_zero=0;
     int count_one=0;
     int count_two=0;
     for(int i=0;i<A.size();i++)
     {
         if(A[i]==0) count_zero++;
         else if(A[i]==1) count_one++;
         else if(A[i]==2) count_two++;
     }
     int k=0;
    for(int i=0;i<count_zero;i++)
      A[k++]=0;
    for(int i=0;i<count_one;i++)
      A[k++]=1;
    for(int i=0;i<count_two;i++)
      A[k++]=2;

  }
