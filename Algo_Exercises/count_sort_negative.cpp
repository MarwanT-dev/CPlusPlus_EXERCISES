#include <iostream>
#include<vector>
using namespace std;


int findUnsortedSubarray(vector<int>& nums) {

        int first = -1 , end = -1;
        for(int i=0;i<nums.size()-1;i++){
            if(first==-1&&nums[i]>nums[i+1])
                first = i ,end = i+1 ;


            if((nums[i]>nums[i+1])||(nums[i]==nums[i+1]&&nums[end]==nums[i]))
                end = i+1;

        }
        if(first==-1&&end==-1)
            return 0;
        return end-first+1;
    }


int main()
{

    vector<int>v{1,2,3,3,3};
    cout<<findUnsortedSubarray(v);

    return 0;
}
