/* Word ladder path maker
   Written By:Ankush Mitra
   Date:20.12.19 Time:15.52*/
   void construct(string start,string &end,unordered_map<string,vector<string> >& parent,vector<vector<string> >& list,vector<string> &temp)
   {
       if(start==end)
       {
           list.push_back(temp);
           return;
       }
       for(int i=0;i<parent[start].size();i++)
       {
           temp.push_back(parent[start][i]);
           construct(parent[start][i],end,parent,list,temp);
           temp.pop_back();
       }
       return;
   }
   vector<vector<string> > findLadders(string start, string end, vector<string> &dict) {
       // Do not write main() function.
       // Do not read input, instead use the arguments to the function.
       // Do not print the output, instead return values as specified
       // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

       unordered_set<string> S(dict.begin(),dict.end());
       unordered_map<string,vector<string> > parent;
       unordered_map<string,int> dis;
       queue<string> q;
       dis[start]=1;
       q.push(start);
       while(!q.empty())
       {
           string temp=q.front();
           q.pop();
           if(temp==end) break;
           for(int i=0;i<temp.size();i++)
           {
               for(int j=0;j<26;j++)
               {
                   string newS=temp;
                   newS[i]='a'+j;
                   if(S.find(newS)!= S.end())
                   {
                       if(dis[newS]==0)
                       {
                           dis[newS]=dis[temp]+1;
                           parent[newS].push_back(temp);
                           q.push(newS);

                       }
                       else if(dis[newS]==dis[temp]+1)
                       {
                           parent[newS].push_back(temp);
                       }
                   }
               }
           }
       }
       vector<vector<string> > list;
       vector<string> temp;
       temp.push_back(end);
       if(dis[end]==0)
         return list;
       else
       {
           construct(end,start,parent,list,temp);
           for(int i=0;i<list.size();i++)
           {
               reverse(list[i].begin(),list[i].end());
           }
           return list;

       }
   }
