/* Generate Prefix code for a list of string
   Written By:Ankush Mitra
   Date:19.12.19 TIme:00.27*/
   struct trie{
       int count;
       trie* ch[26];
       trie()
       {
           count=0;
           for(int i=0;i<26;i++)
           {
               ch[i]=NULL;
           }
       }
   };
   void insert(trie* root,string s)
   {
       trie * temp=root;
       for(int i=0;i<s.size();i++)
       {
           if(temp->ch[s[i]-'a']==NULL) temp->ch[s[i]-'a']=new trie();
           temp=temp->ch[s[i]-'a'];
           temp->count++;
       }
   }
   int positionOfUnique(trie * root,string s)
   {
       trie * temp=root;
       for(int i=0;i<s.size();i++)
       {
           temp=temp->ch[s[i]-'a'];
           if(temp->count==1)
           {
               return i;
           }
       }
       return s.size();
   }
   vector<string> Solution::prefix(vector<string> &A) {

   trie * root= new trie();
   for(int i=0;i<A.size();i++)
   {
       insert(root,A[i]);
   }
   vector<string> list;
   for(int i=0;i<A.size();i++)
   {
       int j=positionOfUnique(root,A[i]);
       list.push_back(A[i].substr(0,j+1));
   }
   return list;
   }
