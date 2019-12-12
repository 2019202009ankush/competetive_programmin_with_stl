/*Find the largest sum subarray with non negative number
  Written By:Ankush Mitra
  Date:12.12.19 Time:14:49*/

vector<int > Solution::maxset(vector<int > &A) {
    long long int  max_sum=-1;
    long long int  max_left=-1;
    long long int  max_right=-1;
    long long int  cur_sum=0;
    long long int  cur_left=0;
    long long int  cur_right=-1;
    long long int  count=0;
    A.push_back(-1);//gurd
    for(long long int  i=0;i<A.size();i++)
    {
        if(A[i]>=0)
        {

             count+=1;//to check all negative or not 
            cur_sum+=A[i];
            // cout<<"A[i"<<A[i]<<" "<<cur_sum<<endl;
            cur_right++;

        }
        else
        {
            if(cur_sum>max_sum)
            {
                // cout<<"HEree"<<endl;

                max_left=cur_left;
                max_right=cur_right;
                max_sum=cur_sum;

            }
            else if(cur_sum==max_sum&&(cur_right-cur_left)>(max_right-max_left))
            {
                max_left=cur_left;
                max_right=cur_right;
                max_sum=cur_sum;
            }
            cur_left=i+1;
            cur_right=i;//1 less as it will line 22
            cur_sum=0;// cur_sum shuold be zero
        }
    }
    vector<int > ans;
    if(count==0)
    {
        return ans;
    }
    else{
        // cout<<max_left<<" "<<max_right<<endl;
        for(long long int  i=max_left;i<=max_right;i++)
        {
            ans.push_back(A[i]);
        }
        return ans;
    }
}
