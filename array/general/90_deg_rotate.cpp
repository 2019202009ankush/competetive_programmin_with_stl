/* 90 deg rotate of matrix
   Written By:Ankush Mittra
   Date:25.12.19 Time:18.19*/
   void Solution::rotate(vector<vector<int> > &A) {
       // Do not write main() function.
       // Do not read input, instead use the arguments to the function.
       // Do not print the output, instead return values as specified
       // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

       for(int i=0;i<A.size();i++)
       {
           for(int j=i+1;j<A.size();j++)
           {
               int temp=A[i][j];
               A[i][j]=A[j][i];
               A[j][i]=temp;
           }
       }
       for(int i=0;i<A.size();i++)
       {
           for(int j=0;j<A.size()/2;j++)
           {
               int temp=A[i][j];
               A[i][j]=A[i][A.size()-j-1];
               A[i][A.size()-j-1]=temp;
           }
       }
   }
