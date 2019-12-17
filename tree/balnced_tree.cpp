/* Balenced Tree from sorted Array
   Written By:Ankush Mitra
   Date:18.12.19 Time:1.56*/
   TreeNode* help(const vector<int> &A,int l,int h)
   {

       if(A.size()==0)
         return NULL;
       if(l<0||h>=A.size()||l>h) return NULL;
       else
       {
           // cout<<l<<" "<<h<<endl;
           int mid=(l+h)/2;
           TreeNode *t =new TreeNode(A[mid]);
           t->left=help(A,l,mid-1);
           t->right=help(A,mid+1,h);
           return t;
       }
   }
   TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
       return help(A,0,A.size()-1);
   }
