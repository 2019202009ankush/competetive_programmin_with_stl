/* find if there is two pair of int such that sum of them is k
   Written By:Ankush Mitra
   Date:15.12.19 Time:22.16*/

    void find_(TreeNode * root,set<int>&s,bool &ans,int B)
    {
        if(!root)
        {
             return;//simply return as may be in other chain ans may be true
        }
        if(s.find(B-root->val)!=s.end())
        {
            ans=true;
            return;
        }
        else
        {
            s.insert(root->val);
           if(!ans) find_(root->left,s,ans,B);//if ans is set not no more call
           if(!ans) find_(root->right,s,ans,B);// finally root will return
        }
    }
   int t2Sum(TreeNode* A, int B) {
       set<int>s;
       bool ans=false;
       find_(A,s,ans,B);
       return ans;
   }
