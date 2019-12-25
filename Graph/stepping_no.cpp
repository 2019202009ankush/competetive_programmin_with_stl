/* Find all stepping number
   Written By:ANkush Mitra
   Date:22.12.19 Time:17.12*/
   vector<int> Solution::stepnum(int A, int B) {
       vector<int> ans;
       if(A<=0)  ans.push_back(0);
       queue<int> q({1,2,3,4,5,6,7,8,9});
       while(q.front()<=B)
       {
           int temp=q.front();
           q.pop();
           if(temp>=A)
           ans.push_back(temp);
           int lastDigit=temp%10;
           if(lastDigit>0)q.push(temp*10+ lastDigit-1);
           if(lastDigit<9)q.push(temp*10 + lastDigit+1);

       }
       return ans;
   }
