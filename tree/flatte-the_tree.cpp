/* Flatten The tree
   Written By:Ankush Mitra
   Date:16.12.19 Time:2:00*/

   TreeNode* flatten(TreeNode* B) {
       if(!B)
         return NULL;
       TreeNode * A=B;
       //rule is to make left rightmost leaf rigght node right and node left will be node right and then node right
       while(A)
       {
           if(A->left)
           {
               TreeNode * rightMost=A->left;
               while(rightMost->right)
               {
                   rightMost=rightMost->right;
               }
               rightMost->right=A->right;
               A->right=A->left;
               A->left=NULL;

           }
           A=A->right;
       }
       return B;

   }
