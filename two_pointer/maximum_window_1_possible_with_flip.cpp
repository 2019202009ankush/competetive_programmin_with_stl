/* Find out Largest Window Such that all zero filp will make max contigeous 1
   Written By:Ankush Mitra
   Date:14.12.19 Time:22.29*/
   vector<int> maxone(vector<int> &A, int m) {
       int bestWindow=0;
       int CurrentWindowLeft=0;
       int CurrentWindowRight=0;
       int bestWindowLeft=0;
       int count_zero=0;
       while(CurrentWindowRight<A.size())
       {
           if(count_zero<=m)
           {
               if(A[CurrentWindowRight]==0)
                  count_zero++;
               CurrentWindowRight++;
           }
           if(count_zero>m)
           {
               if(A[CurrentWindowLeft]==0)
                 count_zero--;
               CurrentWindowLeft++;
           }
           if(bestWindow<(CurrentWindowRight-CurrentWindowLeft))
           {
               bestWindow=CurrentWindowRight-CurrentWindowLeft;
               bestWindowLeft=CurrentWindowLeft;
           }
       }
       vector<int>Q;
       for(int i=0;i<bestWindow;i++)
       {
           Q.push_back(bestWindowLeft+i);
       }
       return Q;
   }
