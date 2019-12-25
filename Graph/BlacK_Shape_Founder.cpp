/* Find out all Black shape
   Written By: Ankush Mitra
   Date:22.12.19 Time: 15.27*/
   int dfs(int startX,int startY,int N,int M,vector<string> &A,int ** vis,int dx[],int dy[])
   {
       vis[startX][startY]=1;
       int count=1;
       for(int i=0;i<4;i++)
       {
         int newX=startX+dx[i];
         int newY=startY+dy[i];
         if(newX>=0&&newY>=0&&newX<N&&newY<M&&vis[newX][newY]==0&&A[newX][newY]=='X')
         {
           //   cout<<newX<<" "<<newY<<endl;
             count+=dfs(newX,newY,N,M,A,vis,dx,dy);
         }
       }
       return count;

   }
   int Solution::black(vector<string> &A) {
       int comp=0;
       int N=A.size();
       int M=A[0].size();
       //
       int ** vis=new int* [N];
       for(int i=0;i<N;i++)
       {
           vis[i]=new int[M];
       }
       // memset(vis,0,sizeof(vis));
       for(int i=0;i<N;i++)
       {
           for(int j=0;j<M;j++)
           {
               vis[i][j]=0;
           }
       }
       // cout<<N<<" "<<M<<endl;
       int dx[4]={1,0,-1,0};
       int dy[4]={0,1,0,-1};
       for(int i=0;i<N;i++)
       {
           for(int j=0;j<M;j++)
           {
               if(A[i][j]=='X'&&vis[i][j]==0)
               {
                   // cout<<i<<" "<<j<<endl;
                   comp++;
                   dfs(i,j,N,M,A,vis,dx,dy);
               }
           }
       }
       return comp;


   }
