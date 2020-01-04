/* Excel Number Reverse
  Written By:Ankush Mitra
  Date:4.1.20 Time:20:56*/
  string Solution::convertToTitle(int A) {
     string s="";
     if(A==1) return "A";
     while(A>0)
     {
       int t=((A-1)%26);
      char c=t+'A';
      s.insert(0,1,c);
       A=(A-1)/26;
     }
      return s;
  }
