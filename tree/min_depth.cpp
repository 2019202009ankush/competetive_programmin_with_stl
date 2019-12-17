/* Min Depth
   Written By:ANkush Mitra
   DAte:17.12.19 Time:14.50*/
int minDepth(TreeNode* A) {
      if(!A)  return INT_MAX;
      else
      {
          int left=minDepth(A->left);
          int right=minDepth(A->right);
          if(left==INT_MAX&&right==INT_MAX)
            return 1;
          else
            return 1+min(left,right);
      }
   }
