/* Kruskal Algorithm
   Written By:Ankush Mitra
   Date:21.12.19 Time:16.46*/
   int find_(int x,unordered_map<int,pair<int,int> >& DSU)
   {
       vector<int> chain;
       while(x!=DSU[x].first)
       {
           chain.push_back(x);
           x=DSU[x].first;

       }
       for(int i=0;i<chain.size();i++)
       {
           DSU[chain[i]].first=x;
       }
       return x;
   }
   bool Union(int x,int y,unordered_map<int,pair<int,int> >& DSU)
   {
       int px=find_(x,DSU);
       int py=find_(y,DSU);
       if(px!=py)
       {
           if(DSU[px].second<DSU[py].second)
           {
               DSU[px].first=py;
               DSU[py].second+=DSU[px].first;
           }
           else
           {
               DSU[py].first=px;
               DSU[px].second+=DSU[py].second;
           }
           return true;
       }
       else return false;

   }
   int Solution::solve(int A, vector<vector<int> > &B) {
      vector<pair<int,pair<int,int> > > graph;
      for(int i=0;i<B.size();i++)
      {
          pair<int,pair<int,int> > t;
          t.first=B[i][2];
          t.second.first=B[i][0];
          t.second.second=B[i][1];
          graph.push_back(t);
      }
      sort(graph.begin(),graph.end());
      unordered_map<int,pair<int,int> > DSU;
      for(int i=1;i<=A;i++)
      {
          DSU[i]={i,0};

      }
      int total_sum=0;
      for(int i=0;i<graph.size();i++)
      {
          int source=graph[i].second.first;
          int des=graph[i].second.second;
          if(Union(source,des,DSU)) total_sum+=graph[i].first;
      }
      return total_sum;

   }
