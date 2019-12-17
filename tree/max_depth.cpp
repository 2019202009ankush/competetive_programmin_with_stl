/* MAx depth
  Written By :ANkush Mitra
  Date:17.12.19 Time:14.28*/
  int maxDepth(TreeNode* A) {
      if(!A) return 0;
      else
      {
          int left=maxDepth(A->left);
          int right=maxDepth(A->right);
          return 1+max(left,right);
      }
  }
