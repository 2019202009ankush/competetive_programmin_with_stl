/* path sum
   Written By:Ankush Mitra
 Date:18.12.19 Time:13.31*/
 int help(TreeNode * A,int rS,int B)
 {
      B=B+A->val;

     if(!A->left&&!A->right)
     {
       if(B==rS)
       {
          return 1;
       }
       else
       {
             return 0;
       }
     }

     else if(!A->right) return help(A->left,rS,B);
     else if(!A->left)   return help(A->right,rS,B);
     else return help(A->left,rS,B)||help(A->right,rS,B);

 }
 int Solution::hasPathSum(TreeNode* A, int B) {
     return help(A,B,0);
 }
