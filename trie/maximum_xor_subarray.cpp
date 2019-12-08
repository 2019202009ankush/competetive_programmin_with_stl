/* Find Maximum Xor subarray in a array
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
   int  findXorMax(Trie * head,int currentVal)
   {

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

       return curr;
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
      int maxi=INT_MIN;
      insert(head,arr[0]);
      int prevXor=arr[0];
      /* concept is all each index form 1 to n-1
         we try to find xor max of all subarry ending at that index
         for example at index=2 there are three subarry possible that ends at index 2 - (0,1,2),(1,2),(2)
         now in trie I have all xor stored form 0 to i-1 now if i find max val cooresponding to XOR(0,1,2) I will get max of all sub array  xor ending
         at i*/
      for(int i=1;i<n;i++)
      {
          prevXor=prevXor^arr[i];
          insert(head,prevXor);
          maxi=max(maxi,findXorMax(head,prevXor));
      }
      cout<<maxi<<endl;

   }
