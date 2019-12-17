/* check identical tree
   Written By:Ankush Mitra
   Date:16.12.19 Time:2.38*/
   int isSameTree(TreeNode* A, TreeNode* B) {
       if(A==NULL&&B==NULL)
         return 1;
       else if(A==NULL||B==NULL)
       {
           return 0;
       }
       else
       {
           return (A->val==B->val)&&isSameTree(A->left,B->left)&&isSameTree(A->right,B->right);
       }
   }
