#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt {};
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0&&k!=0){
                k--;
                cnt+=(-nums[i]);continue;
            }
            else if(k!=0){
                if(k%2!=0)
                    cnt+=(-nums[i]);
                else{

                cnt+=nums[i];
                }
                k=0;

            }
            else
            cnt+=nums[i];

        }
        return cnt;
}

int Search(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0,r = size-1;
        int mid = (l+r)/2;
        while(l<=r){
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
            mid = (l+r)/2;
        }
        return -1;
    }
int main()
{
    vector<int>dist {5,7,7,8,8,10};
    vector<int> speed {1,1,5,3,1};
    // .75  2
    cout<<Search(dist,9);

    return 0;
}
