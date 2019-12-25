/* Roman to integer
   Writtten By:ANkush Mitra
   Date:23.12.19 Time:8.53*/
   int Solution::romanToInt(string A) {
       map<char,int> m;
       m['I']=1;
       m['V']=5;
       m['X']=10;
       m['L']=50;
       m['C']=100;
       m['D']=500;
       m['M']=1000;
       int sum=0;
       for(int i=0;i<A.size();i++)
       {
           if(m[A[i]]<m[A[i+1]])
           {
               sum+=(m[A[i+1]]-m[A[i]]);
               ++i;
           }
         else  sum+=m[A[i]];
       }
       return sum;
   }
