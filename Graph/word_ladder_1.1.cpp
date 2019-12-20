/* Word ladder at each step you can change only one char from source and the the modified word should be present in dictionary
  Written By:Ankush Mitra
  Date:20.12.19 Time:14.29*/
  int solve(string A, string B, vector<string> &C) {
      unordered_set<string> S(C.begin(),C.end());
      unordered_map<string,bool> vis;
      unordered_map<string,int>dis;
      queue<string> q;
      q.push(A);
      vis[A]=1;
      dis[A]=1;
      while(!q.empty())
      {
          string temp=q.front();
          q.pop();
          for(int i=0;i<temp.size();i++)
          {

              for(int j=0;j<26;j++)
              {
                   string newS=temp;
                  newS[i]='a'+j;
                  if(S.find(newS)!=S.end()&&vis[newS]==0)
                  {
                      vis[newS]=1;
                      dis[newS]=dis[temp]+1;
                      if(newS==B) goto l1;
                      q.push(newS);
                  }
              }
          }
      }
      l1:
       if(vis[B]==0) return 0;
       else
       return dis[B];
  }
