/* smallest prime sequence made by 3 given Prime_
   Written By:Ankush Mitra
   Date:19.12.19 Time:21.26*/
   vector<int> Solution::solve(int A, int B, int C, int D) {
       int next_A=A;
       int next_B=B;
       int next_C=C;
       int m=0,n=0,p=0;
       vector<int>list(D+1,1);
       for(int i=1;i<=D;i++)
       {
           int mini=min(min(next_A,next_B),next_C);
           list[i]=mini;
           if(mini==next_A)
           {
               m++;
               next_A=list[m]*A;
           }
           if(mini==next_B)
           {
               n++;
               next_B=list[n]*B;
           }
            if(mini==next_C)
           {
               p++;
               next_C=list[p]*C;
           }
       }
       return vector<int>(list.begin()+1,list.end());
   }
