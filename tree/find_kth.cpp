/* Find out kth element from the tree
   Written by: Ankush Mitra
   Date:17.12.19 Time:1.40*/
   int find_number_of_element(TreeNode* A)
   {
       if(!A) return 0;
       else
       {
           int left_=find_number_of_element(A->left);
           int right_=find_number_of_element(A->right);
           return 1+left_+right_;
       }
   }
   int help(TreeNode* A,int B)
   {
       // cout<<A->val<<endl;
       int total=find_number_of_element(A);
       int left_=find_number_of_element(A->left);
       int right_=total-left_-1;
       int root=left_+1;
       if(B>total||B<1) {
           // cout<<B<<" "<<A->val<<" "<<left_<<" "<<right<<endl;
           return 0;
       }
       if(root==B)
         return A->val;
       else if(B<=left_)
       {
           return help(A->left,B);
       }
       else
       {
           return help(A->right,B-left_-1);
       }

   }
   int Solution::kthsmallest(TreeNode* A, int B) {
       return help(A,B);
   }
