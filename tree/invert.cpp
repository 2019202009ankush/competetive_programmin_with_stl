/*Invert the binary tree
  Written BY:Ankush Mitra
 Date:17.12.19 Time:1.10*/
 TreeNode* help(TreeNode* A)
  {
      if(!A)
       return NULL;
      if(!A->left&&!A->right)
        return A;
      TreeNode* left=help(A->left);
      TreeNode *right=help(A->right);
      A->left=right;
      A->right=left;
      return A;

  }
 TreeNode* invertTree(TreeNode* A) {
   return help(A);
 }
