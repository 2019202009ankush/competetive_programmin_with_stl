/* sum 0 triplet
  Written By:Ankush Mitra
  Date:14.12.19 Time:14:43*/
  vector<vector<int> > threeSum(vector<int> &A) {
      sort(A.begin(),A.end());
      vector<vector<int> > ans;
      if(A.size()<=2)
      {
          return ans;
      }
      for(int i=0;i<A.size()-2;i++)
      {
          int pointer1=i+1;
          int pointer2=A.size()-1;
          while(pointer1<pointer2)
          {
              int sum=A[i]+A[pointer1]+A[pointer2];
              if(sum==0)
              {
                  vector<int> temp;
                  temp.push_back(A[i]);
                  temp.push_back(A[pointer1]);
                  temp.push_back(A[pointer2]);
                  if(find(ans.begin(),ans.end(),temp)==ans.end())//can maintain a unordered_map to check in O(1)
                  {
                      ans.push_back(temp);
                  }
              }
              if(sum>0)
              {
                  pointer2--;
              }
              else
              {
                  pointer1++;
              }
          }
      }
      return ans;
  }
