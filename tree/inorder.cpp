/* Find inorder sequence
   Written By:Ankush Mitra
   Date:16.12.19 Time:23.39*/
   void inorder(TreeNode *A,vector<int>&v)
   {
       if(A)
       {
           if(A->left) inorder(A->left,v);
           v.push_back(A->val);
           if(A->right) inorder(A->right,v);
       }
   }
   vector<int> Solution::inorderTraversal(TreeNode* A) {
       vector<int> v;
       inorder(A,v);
       return v;



   }
