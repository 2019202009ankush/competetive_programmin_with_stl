/* Mark all zero surrounded by X
   Written By:Ankush Mitra
   Date:22.12.19 Time:16.17*/
   void dfs(int startX,int startY,int N,int M,int ** vis,vector<vector<char> > &A,bool & isEnd ,vector<pair<int,int> >&Pair,int dx[],int dy[])
   {
       vis[startX][startY]=1;
       if(startX==0||startY==0||startX==N-1||startY==M-1) isEnd=1;
       for(int i=0;i<4;i++)
       {
           int newX=startX+dx[i];
           int newY=startY+dy[i];
           if(newX>=0&&newX<N&&newY>=0&&newY<M&&vis[newX][newY]==0&&A[newX][newY]=='O')
           {
               dfs(newX,newY,N,M,vis,A,isEnd,Pair,dx,dy);
           }
       }
       Pair.push_back({startX,startY});
   }
   void Solution::solve(vector<vector<char> > &A) {
       // Do not write main() function.
       // Do not read input, instead use the arguments to the function.
       // Do not print the output, instead return values as specified
       // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
      int dx[4]={1,0,-1,0};
      int dy[4]={0,1,0,-1};
      int N=A.size();
      int M=A[0].size();
      int ** vis=new int * [N];
      for(int i=0;i<N;i++)
      {
          vis[i]=new int[M];
      }
      for(int i=0;i<N;i++)
      {
          for(int j=0;j<M;j++)
          {
              vis[i][j]=0;
          }
      }
      bool isEnd=false;
      vector<pair<int,int> >Pair;
      for(int i=0;i<A.size();i++)
      {
          for(int j=0;j<A[i].size();j++)
          {
              if(A[i][j]=='O'&&vis[i][j]==0)
              {
                  dfs(i,j,N,M,vis,A,isEnd,Pair,dx,dy);
                  if(!isEnd)
                  {
                      for(int k=0;k<Pair.size();k++)
                      {
                          A[Pair[k].first][Pair[k].second]='X';
                      }
                  }
                  isEnd=0;
                  Pair.clear();
              }
          }
      }

   }
