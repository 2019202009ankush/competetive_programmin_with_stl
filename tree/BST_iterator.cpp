/*BST iterator
  Written BY:Ankush Mitra
  Date:15.12.19 Time:23.33*/

  stack<TreeNode *> s;

  void pushAll(TreeNode* root)
  {
      while(root)
      {
          s.push(root);
          root=root->left;
      }
  }
  BSTIterator::BSTIterator(TreeNode *root) {
       pushAll(root);
  }

  /** @return whether we have a next smallest number */
  bool BSTIterator::hasNext() {
     return !s.empty();
  }

  /** @return the next smallest number */
  int BSTIterator::next() {
      TreeNode* res=s.top();
      s.pop();
      pushAll(res->right);
      return res->val;

  }

  /**
   * Your BSTIterator will be called like this:
   * BSTIterator i = BSTIterator(root);
   * while (i.hasNext()) cout << i.next();
   */
