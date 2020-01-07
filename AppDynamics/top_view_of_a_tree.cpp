/* Print top view of a Tree
  Written By:ANkush Mitra
  Date:22.31 Time:22.31*/

      void topView(Node * root) {
          if(!root)
          {
              cout<<"";
              return ;
          }
          map<int,int> m;
          int hd=0;
          queue<pair<Node*,int> > q;
          q.push({root,hd});
          while(!q.empty())
          {
              auto t=q.front();
              if(m.find(t.second)==m.end())
              m[t.second]=t.first->data;
              q.pop();
              if(t.first->left)
              {
                  q.push({t.first->left,t.second-1});

              }
              if(t.first->right)
              {
                  q.push({t.first->right,t.second+1});
              }
          }
          for(auto it=m.begin();it!=m.end();it++)
          {
              cout<<it->second<<" ";
          }


      }
