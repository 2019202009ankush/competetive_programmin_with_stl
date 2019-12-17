/* Check is Height_Balenced or not
   Written By:Ankush Mitra
   Date:15.12.19 Time:22.37*/

   int height(TreeNode *A)
   {
       if(!A)
         return -1;
       else
       {
           int left_h=height(A->left);
           int right_h=height(A->right);
           return 1+max(left_h,right_h);
       }
   }
   int is_help(TreeNode* A)
   {
       if(!A) return 1;
       else
       {
           int isLeftBalenced=is_help(A->left);
           int isRightBalenced=is_help(A->right);
           int left_height=height(A->left);
           int right_height=height(A->right);
           return isLeftBalenced&&isRightBalenced&&(abs(left_height-right_height)<=1);
       }
   }
   int isBalanced(TreeNode* A) {
       return is_help(A);
   }
