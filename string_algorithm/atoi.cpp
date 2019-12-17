/* Atoi
   Written By:Ankush Mitra
   Date:17.12.19 Time:19.50*/
   int atoi(const string A) {
       stringstream ss(A);
       long long int i;
       ss>>i;
       if(i>INT_MAX)
        i=INT_MAX;
       else if(i<INT_MIN)
         i=INT_MIN;
        return i;
   }
