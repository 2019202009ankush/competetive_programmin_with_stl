/* Hotel review
   Written By:Ankush Mitra
   Date:19.12.19 Time:2.20*/
   struct trie{
       bool isLeaf;
       trie* ch[26];
       trie()
       {
           isLeaf=false;
           for(int i=0;i<26;i++)
           {
             ch[i]=NULL;
           }
       }
   };


   void insert(trie * head , string s)
   {
       trie* root=head;
       // cout<<"insert "<<s<<endl;
       for(int i=0;i<s.size();i++)
       {
           // cout<<s[i]<<endl;
           if(root->ch[s[i]-'a']==NULL) { root->ch[s[i]-'a']=new trie();}
           root=root->ch[s[i]-'a'];
       }
       root->isLeaf=true;
   }
   bool isPresent(trie * head,string s)
   {
      trie * root=head;
      for(int i=0;i<s.size();i++)
      {
          root=root->ch[s[i]-'a'];
          if(!root) return 0;
      }
      return root->isLeaf;
   }
   vector<string> token_(string A)
   {

       vector<string> list;
       stringstream ss(A);
       string temp;
       while(getline(ss,temp,'_'))
       {
           list.push_back(temp);
       }
       return list;
   }
   bool comp(pair<int,int> a,pair<int,int> b)
   {
       return (a.first>b.first)||(a.first==b.first)&&(a.second<b.second);
   }
   vector<int> Solution::solve(string A, vector<string> &B) {
       trie * root=new trie();
       vector<string> list=token_(A);
       for(int i=0;i<list.size();i++)
       {
           insert(root,list[i]);
       }
       vector<pair<int,int> > reviews;
       for(int i=0;i<B.size();i++)
       {
           string temp=B[i];
           vector<string>list1=token_(temp);
           int count=0;
           for(int i=0;i<list1.size();i++)
           {
               // cout<<isPresent(root,list1[i])<<" "<<list1[i]<<endl;
               if(isPresent(root,list1[i])) count++;
           }
           reviews.push_back({count,i});

       }
       vector<int> K;
       sort(reviews.begin(),reviews.end(),comp);

       for(int i=0;i<reviews.size();i++)
       {
           // cout<<reviews[i].first<<" "<<reviews[i].second<<endl;
           K.push_back(reviews[i].second);
       }

       return K;

   }
