/* Zigzag tree order traversal
 Written By:Ankush Mitra
 Date:18.12.19 Time:01:08*/
 vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
     vector<vector<int> > q;
    if(!A) return q;
    else
    {
        queue<TreeNode * > Q;
        Q.push(A);
        int count=0;
        while(!Q.empty())
        {
            int nodeCount=Q.size();
            vector<int> v;
            while(nodeCount)
            {
                TreeNode * t=Q.front();
                v.push_back(t->val);
                Q.pop();
                if(t->left) Q.push(t->left);
                if(t->right)Q.push(t->right);
                nodeCount--;
            }
            if (count==0)
            {count=1-count;q.push_back(v);}
            else
            {
                count=1-count;
                reverse(v.begin(),v.end());
                q.push_back(v);
            }
        }
        return q;

        }
    }
