/* Construct tree from inorder PostOrder
   Written By:Ankush Mitra
   Date:1.3.20 Time:22.38*/
   int search(vector<int>&B,int start,int val,int end)
   {
       for(int i=start;i<=end;i++)
       {
           if(B[i]==val)
              return i;
       }
       return -1;
   }
  TreeNode * util(vector<int>&A,vector<int>&B,int start,int end,int& post)
  {
      if(post<0) return NULL;
      if(start>end) return NULL;
      TreeNode * t=new TreeNode(A[post--]);
      int posr=search(B,start,t->val,end);
      if(start==end)
        return t;
      t->right=util(A,B,start,posr-1,post);
      t->left=util(A,B,posr+1,end,post);


      return t;

  }
  TreeNode* Solution::buildTree(vector<int> &B, vector<int> &A) {
      int post=A.size()-1;
      return util(A,B,0,B.size()-1,post);
  }
