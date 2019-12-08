/* Find Maximum Xor Pair in a array
   Written By:Ankush Mitra
   Date:8.12.19 Time:16.20*/
   #include<bits/stdc++.h>
   using namespace std;
   typedef struct Trie
   {
       struct Trie * left;
       struct Trie * right;
       Trie()
       {
           left=NULL;
           right=NULL;
       }
   }Trie;
   void insert(Trie* head,int n)
   {
      Trie *root=head;
      for(int i=31;i>=0;i--)
      {
          int bitValue=(n>>i)&1;
          if(bitValue==1)
          {
              if(!root->right) root->right=new Trie();
              root=root->right;
          }
          else
          {
              if(!root->left) root->left=new Trie();
              root=root->left;
          }
      }
   }
   int  findXorMax(Trie * head,int arr[],int n)
   {
       int maxi=INT_MIN;
       for(int i=0;i<n;i++)
       {
           int currentVal=arr[i];
           Trie * root=head;
           int curr=0;
           for(int j=31;j>=0;j--)
           {
               int bitValue=(currentVal>>j)&1;
               if(bitValue==0)
               {
                   if(root->right)
                   {
                       curr+=pow(2,j);
                       root=root->right;
                   }
                   else if(root->left)
                   root=root->left;
               }
               else
               {
                   if(root->left) {
                       curr=curr+pow(2,j);
                       root=root->left;
                   }
                   else if(root->right)
                   root=root->right;
               }
           }
           maxi=max(maxi,curr);
       }
       return maxi;
   }

   int main()
   {
       int n;
       cin>>n;
       int arr[n];
       Trie * head= new Trie();

       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
      for(int i=0;i<n;i++)
      {

          insert(head,arr[i]);
      }
       cout<<findXorMax(head,arr,n);
   }
