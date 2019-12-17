/* Sum up two binary string
   Written By:ANkush Mitra
   Date:17.12.19 Time:19.12*/
   string Solution::addBinary(string A, string B) {
       if(A.size()<B.size())
       {
           string C=A;
           A=B;
           B=C;
       }
       int i=A.length()-1;
       int j=B.length()-1;
       int carry=0;
       while(i>=0&&j>=0)
       {
         if(((A[i]-'0')+(B[j]-'0')+carry)==3)
         {
             A[i]='1';
             carry=1;

         }
         else if(((A[i]-'0')+(B[j]-'0')+carry)==2)
         {
             A[i]='0';
             carry=1;

         }
         else if(((A[i]-'0')+(B[j]-'0')+carry)==1)
         {
             A[i]='1';
             carry=0;

         }
         else if(((A[i]-'0')+(B[j]-'0')+carry)==0)
         {
             A[i]='0';
             carry=0;

         }
         i--;
         j--;
       }
       while(i>=0)
       {
           if((A[i]-'0')+carry==2)
           {
               A[i]='0';
               carry=1;
           }
           else if((A[i]-'0')+carry==1)
           {
               A[i]='1';
               carry=0;
           }
           else if((A[i]-'0')+carry==0)
           {
               A[i]='0';
               carry=0;
           }
           i--;
       }
       if(carry)
       {
           string D="1";
           A.insert(0,D);
       }
       return A;
   }
