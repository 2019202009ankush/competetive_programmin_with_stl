/* PostOrder
  Written By:Ankush Mitra
  Date:19.12.19 Time:00.10*/
  void postorder(TreeNode * A,vector<int>&q)
  {
      if(A)
      {
          if(A->left) postorder(A->left,q);
          if(A->right) postorder(A->right,q);
          q.push_back(A->val);
      }
  }
  vector<int> Solution::postorderTraversal(TreeNode* A) {
      vector<int> q;
      postorder(A,q);
      return q;
  }
