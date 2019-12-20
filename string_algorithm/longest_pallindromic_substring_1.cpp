/* Longest palindromic substring
   Written By:Ankush Mitra
   Date:19.12.19 Time:12:31*/
   string Solution::longestPalindrome(string A) {
    int maxi=INT_MIN;
    int center,center1;
    int cas=0;
    for(int i=0;i<A.size();i++)
    {
        //odd
        int l=i;
        int r=i;
        while(l>=0&&r<A.size()&&A[l]==A[r])
        {
            int cur_len=r-l+1;
            if(maxi<cur_len)
            {
                maxi=cur_len;
                center=i;
                cas=0;
            }
            l--;
            r++;
        }
        //even
        l=i;
        r=i+1;
        while(l>=0&&r<A.size()&&A[l]==A[r])
        {
            int cur_len=r-l+1;
            if(maxi<cur_len)
            {
                maxi=cur_len;
                center=i;
                cas=1;
            }
            l--;
            r++;
        }
    }
    string a;
    if(maxi%2==1)
    {
        // cout<<center<<maxi<<center-((maxi)/2)<<endl;
        return A.substr(center-((maxi)/2),maxi);

    }
    else
    {
        // cout<<center<<maxi<<endl;
        return A.substr((center-(maxi-2)/2),maxi);
    }

}
