/* k diff pair
 Written By:Ankush Mitra
 Date:5.1.20 Time:12.55*/
 int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        int count=0;
        sort(nums.begin(),nums.end());
        set<pair<int,int> > s;
        unordered_map<int,int> sm;
        for(int i=0;i<nums.size();i++)
        {
            sm[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(sm.find(k+nums[i])!=sm.end()&&s.find(make_pair(nums[i],k+nums[i]))==s.end()&&sm[k+nums[i]]!=i)
            {
                count++;
                s.insert({nums[i],k+nums[i]});
            }
        }
        return count;
    }
