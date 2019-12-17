/*Check mirror tree
  Written By:Ankush Mitra
  Date:18.12.19 Time:1.23*/
  int help(TreeNode* A ,TreeNode * B)
  {
      if(!A||!B) return A==B;
      if(A->val!=B->val) return 0;
      else return help(A->left,B->right)&&help(A->right,B->left);
  }
  int isSymmetric(TreeNode* A) {
      if(!A)
        return 1;
      else
        return help(A->left,A->right);
  }
