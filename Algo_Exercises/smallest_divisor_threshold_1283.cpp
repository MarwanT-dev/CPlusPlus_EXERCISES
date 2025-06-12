
#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int sum_after_division(vector<int>&nums ,int n){
    int sum = 0;
    for(int i =0;i<nums.size();i++){
        sum+=((nums[i]+n-1)/n);
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int l = 0 , r = *max_element(nums.begin(),nums.end());
    int mid = (l+r)/2;//l+(r-l)/2;
    int divisor = -1;

    while(l<=r){
        if(sum_after_division(nums,mid)>threshold)
            l = mid+1;
        else
            r = mid-1 , divisor = mid;
        mid = (l+r)/2;
    }


    return divisor;
}


int main(){

    vector<int> v = {44,22,33,11,1};
    cout<<smallestDivisor(v,5);

    return 0;
}
