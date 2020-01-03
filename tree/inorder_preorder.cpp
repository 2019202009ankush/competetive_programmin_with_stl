int search(vector<int>&inorder,int start,int v,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==v)
                  return i;
        }
        return -1;
    }
    TreeNode * util(vector<int>&preorder,vector<int>&inorder,int start,int end,int& preI)
    {
        //cout<<start<<" "<<end<<endl;
        if(start>end)  return NULL;
        TreeNode * t=new TreeNode (preorder[preI]);
        preI++;
        if(start==end)  return t;
        int pos=search(inorder,start,t->val,end);
        //cout<<pos<<" "<<t->val<<endl;
        t->left=util(preorder,inorder,start,pos-1,preI);
        t->right=util(preorder,inorder,pos+1,end,preI);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preI=0;
        return util(preorder,inorder,0,inorder.size()-1,preI);

    }
