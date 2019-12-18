/* Path Print with specific sum root to leaf
   Written By:ANkush Mitra
   Date:18.12.19 Time:00:08*/
   void help(TreeNode* A,int B,int CurSum,vector<vector<int> > K,vector<int>temp)
   {
       if(!A)
         return;
       CurSum=CurSum+(A->val);
       temp.push_back(A->val);
       if(!A->left&&!A->right)
       {
           if(CurSum==B)
           {
               K.push_back(temp);
           }
           temp.pop_back();
       }
       help(A->left,B,CurSum,K,temp);
       help(A->right,B,CurSum,K,temp);
       temp.pop_back();
   }
   vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {

    vector<vector<int> > k;
    vector<int>temp;
    help(A,B,0,K,temp);
    return K;

   }
