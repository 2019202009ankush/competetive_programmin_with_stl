/* Find maximum subarray of non negative number in the array
   Written By:ANkush Mitra
   Date:25.12.19  Time:14.08*/
   vector<int> Solution::maxset(vector<int> &A) {
    int left=0;
    int right=0;
    int global_left=0;
    int global_right=0;
    long long int global_max=0;
    long long int  local_max=0;
    bool isAllnegative=true;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=0)
        {
            isAllnegative=false;
            local_max+=A[i];
            right=i;
        }
        else{

            left=i+1;
            right=i+1;
            local_max=0;
        }
          if(global_max<local_max)
            {
                global_max=local_max;
               global_left=left;
               global_right=right;
            //   cout<<"In"<<global_left<<" "<<global_right<<endl;
            }
            else if(global_max==local_max&&(right-left)>(global_right-global_left))
            {
                global_max=local_max;
                global_left=left;
                global_right=right;

            }
    }
  if(isAllnegative)
  return vector<int>();
  else
    return vector<int>(A.begin()+global_left,A.begin()+global_right+1);
}
