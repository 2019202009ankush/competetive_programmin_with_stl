/* Find length of last word
   Written By:Ankush Mitra
   Date:24.12.19 Time:8:47*/
   int Solution::lengthOfLastWord(const string A) {

       if(A.size()==0) return 0;
       else if(A.size()==1) return 1;
       stringstream ss(A);
       string temp;
       int prev=0;
       while(getline(ss,temp,' '))
       {
           prev=temp.size()==0?prev:temp.size();
       }
       return prev;
   }
