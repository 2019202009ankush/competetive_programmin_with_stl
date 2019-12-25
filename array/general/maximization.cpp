/*  Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
   f(i, j) is defined as |A[i] - A[j]| + |i - j|
  Written BY :Ankush Mitra
  Date:25.12.19 Time:12.07*/
  int Solution::maxArr(vector<int> &A) {
      int min1=INT_MAX;
      int maxi1=INT_MIN;
      int min2=INT_MAX;
      int maxi2=INT_MIN;
      for(int i=0;i<A.size();i++)
      {
          maxi1=max(maxi1,A[i]+i);
          min1=min(min1,A[i]+i);
          maxi2=max(maxi2,A[i]-i);
          min2=min(min2,A[i]-i);
      }
      return max(abs(maxi1-min1),abs(maxi2-min2));
  }
