/* Find All the good substring interviewbit
   Written By:Ankush Mitra
   Date:17.12.19 Time:19.21*/
   int Solution::solve(string A) {
       int mod=10003;
       int count=0;
       for(int i=0;i<A.length();i++)
       {
           if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U')
           {
               count=(count%mod + (A.length()-i)%mod +mod)%mod;
           }
       }
       return count;
   }
