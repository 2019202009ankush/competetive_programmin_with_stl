/* Rob the non cosecutive house with max profit house are arranged in circle
   Written By:Ankush Mitra
   Date:21.12.19 Time:23.44*/
   int rob(vector<int>& nums) {
           if(nums.size()==0)
               return 0;
           if(nums.size()==1)
               return nums[0];
           if(nums.size()==2)
               return max(nums[0],nums[1]);
           if(nums.size()==3)
               return max(max(nums[0],nums[1]),nums[2]);
           else
           {
            int dp[nums.size()];
             dp[0]=nums[0];
             dp[1]=max(nums[0],nums[1]);
             int help[nums.size()];
             help[0]=0;
             help[1]=nums[1];
             for(int i=2;i<nums.size();i++)
             {
                 help[i]=max(help[i-1],help[i-2]+nums[i]);
             }
             // dp[2]=max((nums[0],nums[1]),nums[2]);
             int i;
             for(i=2;i<nums.size()-1;i++)
             {
                 dp[i]=max(dp[i-1],(dp[i-2]+nums[i]));
             }

             dp[i]=max(dp[i-1],max(help[i-2]+nums[i],dp[0]));
             return dp[nums.size()-1];

           }
       }
