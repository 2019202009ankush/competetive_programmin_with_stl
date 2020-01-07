/* Find minimum window that contain all element of second string
  Written By:Ankush Mitra
  Date:6.1.20 Time:12.37*/
  string Solution::minWindow(string A, string B) {
    int st=0;
    int n=A.size();
    int m=B.size();
    int ans=INT_MAX;
    int idx=-1;
    int count=0;
    if(m==0||n==0) return "";
    unordered_map<char,int> have,need;
    for(auto it:B)
    {
        need[it]++;
    }
    for(int ed=0;ed<n;ed++)
    {
        if(need[A[ed]]==0) continue;
        have[A[ed]]++;
        if(have[A[ed]]<=need[A[ed]]) count++;
        if(count==m)
        {
            while(have[A[st]]>need[A[st]]||have[A[st]]==0)
            {
                if(have[A[st]]>need[A[st]]) have[A[st]]--;
                st++;

            }
        int temp=ed-st+1;
        if(temp<ans)
        {
            idx=st;
            ans=temp;
        }
        }

    }
    return idx==-1?"":A.substr(idx,ans);
}
