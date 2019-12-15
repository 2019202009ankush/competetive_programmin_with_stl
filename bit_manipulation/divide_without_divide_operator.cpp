/* Find a/b with out using / - %
   Written By: Ankush Mitra
   Date:15.12.19 Time:16.17*/
   int divide(int A, int B) {
       int n1=A<0;
       int n2=B<0;
       long long int a=A;
       long long int b=B;
       a=abs(a);
       b=abs(b);
       double log_a=log(a);
       double log_b=log(b);
       long long int e=exp(log_a-log_b);
       if(n1^n2) e=-e;
       if(e>INT_MAX||e<INT_MIN)
       {
           return INT_MAX;
       }
       else
       {
           return e;
       }
   }
