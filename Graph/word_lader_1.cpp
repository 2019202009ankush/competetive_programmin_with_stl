/* Word ladder Go from source word to dest word using the dict of words
   Wriiten By:Ankush Mitra
   Date:20..12.19 Time:14.16*/
   bool isValid(string a,string b)
   {
       int count=0;
       for(int i=0;i<a.size();i++)
       {
           if(a[i]!=b[i]) count++;
       }
       return count == 1;
   }
   int Solution::solve(string A, string B, vector<string> &C) {
       unordered_map<string,bool>vis;
       unordered_map<string,int>dis;
       queue<string> q;
       q.push(A);
       vis[A]=true;
       dis[A]=1;
       while(!q.empty())
       {
           string temp=q.front();
           q.pop();
           for(int i=0;i<C.size();i++)
           {
               string newS=C[i];
               if(vis[newS]==0)
               {
                   if(isValid(temp,newS))
                   {
                       vis[newS]=1;
                       dis[newS]=1+dis[temp];
                       q.push(newS);
                   }

               }
           }
       }
       if(vis[B]==0)
        return 0;
       else
         return dis[B];

   }
