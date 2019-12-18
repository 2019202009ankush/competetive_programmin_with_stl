/* Find all valid IP address
   Written By:Ankush Mitra
   Date:19.12.19 Time:2.40*/
   bool isValid(string s)
   {
       if(s.size()>1&&s[0]=='0') return false;
       else if(stoi(s)<=255&&stoi(s)>=0) return true;
       else return false;
   }
   vector<string> Solution::restoreIpAddresses(string A) {
      vector<string>list;
      string s=A;
      if(A.size()>12||A.size()<4)
      {
          return list;
      }
      for(int i=1;i<4;i++)
      {
          string first=A.substr(0,i);
          if(!isValid(first)) continue;
          for(int j=1;i+j<s.size()&&j<4;j++)
          {
              string second=A.substr(i,j);
              if(!isValid(second)) continue;
              for(int k=1;i+j+k<s.size() && k<4 ;k++)
              {
                  string third=A.substr(i+j,k);
                  string forth=A.substr(i+j+k);
                  if(isValid(third)&&isValid(forth))
                  {
                      string temp=first+"."+second+"."+third+"."+forth;
                      list.push_back(temp);
                  }
              }
          }

      }
   }
