/* Spirail order
   Written By:Ankush Mitra
   Date:25.12.19 Time:14.41*/

   vector<vector<int> > Solution::generateMatrix(int A) {
       vector<vector<int> >mat(A);
       int w=A;
       for(int i=0;i<w;i++)
       {
           for(int j=0;j<w;j++)
           {
               mat[i].push_back(0);
           }
       }
       int temp=1;
       int i=0,j=0;
       int dir=0;
        while(temp<=A*A)
        {
            mat[i][j]=temp;
            temp++;
            if(dir==0)
            {
                j++;
                if(j==A||mat[i][j]!=0)  {
                    j--;
                    i++;
                    dir=1;
                }
            }
            else if(dir==1)
            {
                i++;
                if(i==A||mat[i][j]!=0)
                {
                    i--;
                    j--;
                    dir=2;
                }
            }
            else if(dir==2)
            {
                j--;
                if(j==-1||mat[i][j]!=0)
                {
                    dir=3;
                    j++;
                    i--;

                }
            }
            else if(dir==3)
            {
                i--;
                if(i==-1||mat[i][j]!=0)
                {
                    dir=0;
                    i++;
                    j++;
                }
            }

        }
        return mat;
   }
