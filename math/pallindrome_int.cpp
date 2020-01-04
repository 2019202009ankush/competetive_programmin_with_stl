/* Palindrome int
  Written By:ankush Mitra
  Date:4.1.20 Time:20.31*/
  int Solution::isPalindrome(int A) {
      if(A<0) return 0;
      string s=to_string(A);
     stack<char>ss;
     for(int i=0;i<s.size();i++)
     {
         ss.push(s[i]);
     }
     for(int i=0;i<s.size();i++)
     {
         if(s[i]==ss.top())
         {
             ss.pop();
         }
         else
         {
             return 0;
         }
     }
     if(ss.empty())
       return 1;
      else return 0;
  }
