/*level order traversal of a tree
  written by:Ankush Mitra
  Date:19.12.19 Time:22.15*/
  /**
   * Definition for binary tree
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   * };
   */
  vector<vector<int> > Solution::levelOrder(TreeNode* A) {
      vector<vector<int> > list;
      if(!A) return list;
      queue<TreeNode * > q;
      q.push(A);
      while(!q.empty())
      {
          vector<int> temp;
          int nodeCount=0;
          nodeCount=q.size();
          while(nodeCount--)
          {
              TreeNode * top=q.front();
              temp.push_back(top->val);
              q.pop();
              if(top->left) q.push(top->left);
              if(top->right) q.push(top->right);
          }
          list.push_back(temp);
      }
      return list;
  }
