/*Find Least Common Ansector of a node
  Written By:ANkush Mitra
  Date:17.12.19 Time:14.23*/
  TreeNode * help(TreeNode * A,int B,int C)
   {
       if(!A) return NULL;
       if(A->val==B||A->val==C) return A;
       TreeNode * l=help(A->left,B,C);
       TreeNode * r=help(A->right,B,C);
       if(l&&r) return A;
     else{
         return l?l:r;
     }

   }
   bool find(TreeNode* A,int key)
   {
       if(!A) return false;
       if(A->val==key) return true;
       else
         return find(A->left,key)||find(A->right,key);
   }
  int lca(TreeNode* A, int B, int C) {
      if(!find(A,B)||!find(A,C)) return -1;
      TreeNode * ans=help(A,B,C);
      if(!ans) return -1;
      else return ans->val;
  }
