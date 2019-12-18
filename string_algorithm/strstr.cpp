/* Find substring in a string
  Written By : Ankush Mitra
  Date:17.12.19 Time:23.17*/
  vector<int> make_lps(string A)
  {
      int j=0;
      int i=1;
      int n=A.size();
      vector<int> lps(n,0);
      while(i<A.size())
      {
          if(A[i]==A[j])
          {
              lps[i]=j+1;
              i++;
              j++;
          }
          else
          {
              if(j==0)
              {
                  lps[i]=0;
                  i++;
              }
              else
              {
                  j=lps[j-1];
              }
          }
      }
      return lps;
  }
  int KMP(string A,string B)
  {
      // cout<<A<<" "<<B<<endl;
      vector<int> lps=make_lps(B);
      int i=0;
      int j=0;
      while(i<A.size()&&j<B.size())
      {
          if(A[i]==B[j])
          {
              i++;
              j++;
          }
          else
          {
              if(j==0)
              {
                  i++;
              }
              else
              {
                  j=lps[j-1];
              }
          }
      }
      if(j==B.size())
      {
          return i-j;
      }
      else return -1;
  }
  int Solution::strStr(const string A, const string B) {
      if(A.size()==0||B.size()==0) return -1;
      else
      {
          // if(A.size()<B.size())
          // {
          //     return KMP(B,A);
          // }
          // else
          return KMP(A,B);

      }
  }
