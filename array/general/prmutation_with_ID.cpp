/* Find the permutation with ID sequence
  Written BY:Ankush Mitra
  Date:28.12.19 Time:18.52*/
  vector<int> Solution::findPerm(const string A, int B) {
      vector<int>v;
      int l=1;
      int r=B;
      int i=0;
    while(l<=r)
    {
        if(A[i++]=='I')
        {
            v.push_back(l++);
        }
        else
        {
            v.push_back(r--);
        }
    }
    return v;
  }
