/* Find Maximum subarry sorting of which make the entire array sorted
   Written By:Ankush Mitra
   Date:30.12.19 Time:11.11*/
vector<int> Solution::subUnsort(vector<int> &A) {
    int right=-1;
    int left=-1;
    int mx=A[0];
    for(int i=1;i<A.size();i++)
    {
        if(A[i]<mx){
            right=i;
        }
        mx=max(mx,A[i]);
    }
  int mn=A[A.size()-1];
  for(int i=A.size()-2;i>=0;i--)
  {
      if(A[i]>mn)
      {
          left=i;
      }
      mn=min(mn,A[i]);
  }
  if(left==-1||right==-1) return {-1};
  else return {left,right};
}
