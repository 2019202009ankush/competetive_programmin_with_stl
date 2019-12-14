/* Remove Duplicates
  Written By:Ankush Mitra
  Date:13.12.19 Time:10:53*/

#include<iostream>
#include<vector>
using namespace std;


vector<int> removeDuplicates(vector<int> input){

    // Write your code here
    int left=0;
    for(int i=1;i<input.size();i++)
    {
        if(input[i]!=input[i-1])
        {
            ++left;
            input[left]=input[i];
        }
    }
    vector<int>ans;
    for(int i=0;i<=left;i++)
    {
       ans.push_back(input[i]);
    }
  return ans;
}
