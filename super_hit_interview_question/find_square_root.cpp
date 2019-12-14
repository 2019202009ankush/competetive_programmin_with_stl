/* Square root of a number
   Written By:ankush mitra
   Date:14.12.19 Time:3:06*/
int Solution::sqrt(int A) {
    if(A<=1)
    {
        return A;
    }
    else
    {
        long long l=1;
        long long h=A;
        long long ans=-1;
        while(l<=h)//this must true
        {
            long long mid=l+(h-l)/2;
            if(mid*mid<=A)//When you want only floor ans the store and move forward
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return (int)ans;
    }

}
