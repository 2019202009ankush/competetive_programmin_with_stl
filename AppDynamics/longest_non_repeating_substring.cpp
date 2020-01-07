/* Longest Non repetating subsstring
   Written By:Ankush Mitra
   Date:19.50 Time:19.50*/
   int Solution::lengthOfLongestSubstring(string A) {

   int ans=0, j=-1;
   unordered_map<char, int> x;

   for(int i=0; i<A.size(); i++){
       if(x.find(A[i]) == x.end()){
           x[A[i]] = i;
           ans = max(i-j, ans);
       }else{
           j = max(x[A[i]], j);
           ans = max(i-j, ans);
           x[A[i]] = i;
       }
   }

   return ans;

   }
