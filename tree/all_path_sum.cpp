/* All path Sum
   Written By:ANkush Mitra
   Date:18.12.19 Time:1.41*/
   int help(TreeNode* A,int curSum)
   {
       curSum=( (curSum*10)%1003 + A->val )%1003;
       if(!A->left&&!A->right) return curSum;
       if(!A->left) return help(A->right,curSum);
       if(!A->right) return help(A->left,curSum);
       else return (help(A->left,curSum)%1003+help(A->right,curSum)%1003)%1003;
   }
   int sumNumbers(TreeNode* A) {
       return help(A,0);

   }
