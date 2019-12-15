/*Find unique number in a array
  Written by:Ankush Mitra
  Date:15.12.19 Time: 17.30*/
  int singleNumber(const vector<int> &A) {
      int val=A[0];
      for(int i=1;i<A.size();i++)
      {
          val=val^A[i];
      }
      return val;
  }
