/* Frog jump
Written By:Ankush Mitra
Date:3.1.20 Time:22.42*/
bool canCross(vector<int>& stones) {
       unordered_map<int,unordered_set<int> > m;
       for(int i=0;i<stones.size();i++)
       {
           m[stones[i]]=unordered_set<int>();

       }
       m[stones[0]].insert(0);
       for(int i=0;i<stones.size();i++)
       {
           int temp=stones[i];
           // cout<<temp<<endl;
           for(auto jumps: m[stones[i]])
           {
               for(int i=jumps-1;i<=jumps+1;i++)
               {
                   // cout<<i<<endl;
                   if(i>0&&m.find(temp+i)!=m.end())
                   {
                       m[temp+i].insert(i);
                   }
               }
           }
       }
       return m[stones.back()].size()>0?1:0;
   }
