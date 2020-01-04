/* Find minimum swtich required to on all blub
  Written By:Ankush Mitra
  Date:3.1.20 TIme:23.08*/
  int Solution::bulbs(vector<int> &A) {
      int find=0;
      int count=0;
      for(int i=0;i<A.size();i++)
      {
          if(A[i]==find)
          {
              count++;
              find=1-find;
          }
      }
      return count;
  }
