/* Find if we can reach form (0,0) to (A,B) via some point that are not within the given circle
   Written By:Ankush Mitra
   Date:19.12.19 Time:22.08*/
   string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
       int rect[A+1][B+1];
       memset(rect,0,sizeof(rect));
       for(int i=0;i<=A;i++)
       {
           for(int j=0;j<=B;j++)
           {
               for(int k=0;k<C;k++)
               {
                   if(sqrt(pow((E[k]-i),2)+pow(F[k]-j,2))<=D)
                   {
                       rect[i][j]=1;
                   }
               }
           }
       }
       if(rect[0][0]==1||rect[A][B]==1)
         return "NO";
       else
       {
           queue<pair<int,int> > Q;
           rect[0][0]=1;
           Q.push({0,0});
           int dx[8]={1,1,0,-1,-1,-1,0,1};
           int dy[8]={0,1,1,1,0,-1,-1,-1};
           while(!Q.empty()){
               pair<int,int> h=Q.front();
               Q.pop();
               int x=h.first;
               int y=h.second;
               for(int i=0;i<8;i++)
               {
                 int newX=x+dx[i];
                 int newY=y+dy[i];
                 if(newX<0||newX>A||newY<0||newY>B) continue;
                 else
                 {
                     if(newX==A&&newY==B) return "YES";
                     else
                     {
                         if(rect[newX][newY]==0)
                         {
                             rect[newX][newY]=1;
                             Q.push({newX,newY});
                         }
                     }
                 }
               }
           }
           return "NO";


       }
   }
