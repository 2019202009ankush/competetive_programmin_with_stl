/* Find longest common Prefix
   Written By:ANkush Mitra
   Date. 19.12.19 Time:13.22*/
   struct trie{
       int count;
       trie* ch[52];
       trie()
       {
           count=0;
           for(int i=0;i<52;i++)
           {
               ch[i]=NULL;
           }
       }
   };
   void insert(struct trie * root,string s)
   {
       struct trie* temp=root;
       for(int i=0;i<s.size();i++)
       {
           if(temp->ch[s[i]-'A']==NULL){
           temp->ch[s[i]-'A']=new trie();
           }
           temp=temp->ch[s[i]-'A'];
           (temp->count)++;
       }
   }
   int pos(struct trie * root ,string s)
   {
      struct trie* temp=root;
      for(int i=0;i<s.size();i++)
      {
          temp=temp->ch[s[i]-'A'];

          if(temp->count==1||!temp)
           return i;
      }
      return s.size();
   }
   string Solution::longestCommonPrefix(vector<string> &A) {
       struct trie * root= new trie();
       for(int i=0;i<A.size();i++)
       {
           insert(root,A[i]);
       }
       int mini=INT_MAX;
       for(int i=0;i<A.size();i++)
       {
           mini=min(mini,pos(root,A[i]));
       }
       if(A.size()==1)
         return A[0];
       if(mini==0)
         return "";
        else
          return A[0].substr(0,mini);
   }
