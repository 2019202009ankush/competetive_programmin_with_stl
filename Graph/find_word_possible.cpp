/* Find if word is possible inn board
   Written By:ANkush Mitra
   Date:22.12.19 Time: 18.11*/
   bool word_search(int sX,int sY,int &N,int &M,vector<string> &A,string &B,int pos)
   {
       if(sX<0||sY<0||sX>=N||sY>=M)
         return 0;
       if(A[sX][sY]==B[pos])
       {
           if(pos==B.size()-1)
           {
               return true;
           }
           else{
               bool l=word_search(sX-1,sY,N,M,A,B,pos+1);
               bool r=word_search(sX+1,sY,N,M,A,B,pos+1);
               bool u=word_search(sX,sY+1,N,M,A,B,pos+1);
               bool d=word_search(sX,sY-1,N,M,A,B,pos+1);
               return (l||r||u||d);
           }
       }
       else
         return false;
   }
   int Solution::exist(vector<string> &A, string B) {
       bool isFound=0;
       int N=A.size();
       int M=A[0].size();
       for(int i=0;i<N;i++)
       {
           for(int j=0;j<M;j++)
           {
               if(A[i][j]==B[0])
               {
                   isFound=isFound||word_search(i,j,N,M,A,B,0);
               }
           }
       }
       if(isFound)
         return 1;
       else
         return 0;
   }
