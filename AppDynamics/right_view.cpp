/* Right view of a tree
  Written By:Ankush Mitra
  Date:6.1.20 Time:21.53*/
  vector<int> rightSideView(TreeNode* root) {
          if(!root) return {};
          queue<TreeNode*> q;

          q.push(root);
          vector<int>l;
          while(!q.empty())
          {
             int s=q.size();
              vector<int>v;
              while(s--)
              {
                  auto t=q.front();
                  v.push_back(t->val);
                  q.pop();
                  if(t->left)
                       q.push(t->left);
                  if(t->right)
                      q.push(t->right);
              }
              l.push_back(v.back());
          }
          return l;
      }
