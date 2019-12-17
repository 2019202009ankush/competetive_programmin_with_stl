/* Make a cartisian tree form inorder
   Written By:Ankush Mitra
   Date:17.12.19 Time:00:46*/
   int position(vector<int>&A,int l,int h)
   {
       int maxi=INT_MIN;
       int maxiindex=-1;
       for(int i=l;i<=h;i++)
       {
           if(maxi<A[i])
           {
               maxi=A[i];
               maxiindex=i;
           }
       }
   return maxiindex;
   }
   TreeNode*  make_tree(vector<int>&A,int l,int h)
   {
       if(l==h)
       return new TreeNode(A[l]);
       if(l>h)
         return NULL;
       else
       {
           int i=position(A,l,h);
           TreeNode * t=new TreeNode(A[i]);
           t->left=make_tree(A,l,i-1);
           t->right=make_tree(A,i+1,h);
           return t;
       }
   }
