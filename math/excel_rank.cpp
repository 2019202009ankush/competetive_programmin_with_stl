/* Excel Rank
   Written BY:ANkush Mitra
   Date:4/1/20 Time:20.39*/
   int Solution::titleToNumber(string A) {
       int count=0;
       for(int i=A.size()-1;i>=0;i--)
       {
           count+=(A[i]-'A'+1)*pow(26,A.size()-1-i);
       }
       return count;
   }
