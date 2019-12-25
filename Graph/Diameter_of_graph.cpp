/* Diameter of the graph
   Written By:Ankush Mitra
   Date:22.12.19  Time:16.57*/
   pair<int,int> bfs(int start, int N,vector<int>graph[])
   {
       int vis[N];
       int dis[N];
       memset(vis,0,sizeof(vis));
       memset(dis,0,sizeof(dis));
       queue<int> q;
       vis[start]=1;
       q.push(start);
       while(!q.empty())
       {
           int temp=q.front();
           q.pop();
           for(int i=0;i<graph[temp].size();i++)
           {
               if(vis[graph[temp][i]]==0)
               {
                   vis[graph[temp][i]]=1;
                   dis[graph[temp][i]]=1+dis[temp];
                   q.push(graph[temp][i]);
               }
           }
       }
       int maxi=INT_MIN;
       int maxiIx=-1;
       for(int i=0;i<N;i++)
       {
           if(maxi<dis[i])
           {
               maxi=dis[i];
               maxiIx=i;
           }
       }
       return make_pair(maxiIx,maxi);

   }
   int Solution::solve(vector<int> &A) {
       // make graph
       int N=A.size();
       vector<int>graph[N];
       for(int i=0;i<A.size();i++)
       {
           if(A[i]==-1) continue;
           else
           {
               graph[i].push_back(A[i]);
               graph[A[i]].push_back(i);
           }
       }
       pair<int,int> firstEnd=bfs(0,N,graph);
       pair<int,int> secondEnd=bfs(firstEnd.first,N,graph);
       return secondEnd.second;
   }
