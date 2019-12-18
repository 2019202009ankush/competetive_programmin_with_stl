/* Count and stay
  Written By:Ankuh Mitra
  Date:17.12.19 Time:23.00*/
  string Solution::countAndSay(int A) {
      if(A==0) return "";
      if(A==1) return "1";
      else
      {
          string prev="1";
          for(int i=2;i<=A;i++)
          {
              string curr="";
              for(int j=0;j<prev.size();j++)
              {
                  int count=1;
                  while((j+1)<prev.length()&&prev[j]==prev[j+1])
                  {
                      count=count+1;
                      j++;
                  }
                  curr.append(to_string(count)+prev[j]);
              }
              prev=curr;
          }
          return prev;
      }

  }
