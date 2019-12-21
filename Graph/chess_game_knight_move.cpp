/* Chess game find if knight can move from starting to end
   Written By:Ankush Mitra
   Date:21.12.19 Time:23.39*/
   int Solution::knight(int A, int B, int C, int D, int E, int F) {
       int board[A+1][B+1],dis[A+1][B+1];
       memset(board,0,sizeof(board));
       memset(dis,0,sizeof(dis));
       board[C][D]=1;
       queue<pair<int,int> > q;
       q.push({C,D});
       pair<int,int> ds=make_pair(E,F);
       int dx[8]={1,1,2,2,-1,-1,-2,-2};
       int dy[8]={2,-2,1,-1,2,-2,1,-1};
       while(!q.empty())
       {
           pair<int,int> temp=q.front();
           q.pop();

           for(int i=0;i<8;i++)
           {
               int newX=temp.first+dx[i];
               int newY=temp.second+dy[i];
               if(newX<=A&&newX>=1&&newY<=B&&newY>=1&&board[newX][newY]==0)
               {
                   // cout<<newX<<" "<<newY<<endl;
                   board[newX][newY]=1;
                   dis[newX][newY]=1+dis[temp.first][temp.second];
                   q.push({newX,newY});
               }
           }

       }
       // for(int i=1;i<=A;i++)
       // {
       //     for(int j=1;j<=B;j++)
       //     {
       //         cout<<board[i][j]<<" ";
       //     }
       //     cout<<endl;
       // }
       if(board[E][F]==0) return -1;
       else return dis[E][F];

   }
