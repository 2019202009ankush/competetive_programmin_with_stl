/* Zigzag order traversal
  Written BY:ANkush Mitra
  Date:15.23 TIme:15.23*/
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          if(!root) return {};
         queue<TreeNode *> q;
          q.push(root);
          int dir=0;
          vector<vector<int> > ss;
          while(!q.empty())
          {
              int s=q.size();
              vector<int>v;
              cout<<dir<<endl;
              while(s--)
              {

                  TreeNode * t=q.front();
                  v.push_back(t->val);
                  q.pop();
                  if(t->left)
                        q.push(t->left);
                  if(t->right)
                        q.push(t->right);

              }
              if(dir==0)
                {
                  ss.push_back(v);
                  dir=1;
                }
              else
              {
                  reverse(v.begin(),v.end());
                  ss.push_back(v);
                  dir=0;
              }

          }
          return ss;
      }
