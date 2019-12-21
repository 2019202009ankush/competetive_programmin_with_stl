/* Find if it is possible to do all couse given prerequisit
   Writen By:Ankush Mitra
   Date:21.12.19 Time:22.29*/
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
   int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    unordered_map<int,pair<int,int> > DSU;
    for(int i=1;i<=A;i++)
    {
        DSU[i].first=i;
        DSU[i].second=0;
    }
    for(int i=0;i<B.size();i++)
    {
        if(Union(B[i],C[i],DSU)==0)
        {
            return 0;
        }

    }

    return 1;

   }
