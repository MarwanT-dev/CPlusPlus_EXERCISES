 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;

 int Search(vector<int>& nums, int target,int init_l) {
        int size = nums.size();
        int l = init_l,r = size-1;
        int mid = (l+r)/2;
        int idx = -1;
        int cnt{};
        while(l<=r){//here's the error
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                idx = mid;
                l = mid+1;

            }
            else{
                r = mid-1;
            }
            mid = (l+r)/2;
        }
        return idx==nums.size()?idx-1:idx;
    }

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt{};
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0)continue;

            for(int j = i+1;j<nums.size()-1;j++){
                int idx = Search(nums,nums[i]+nums[j],j+1);
                if(idx>j)
                    cnt+=(idx-j);
            }
        }
        return cnt;
    }

    int main(){
    vector<int>nums{82,15,23,82,67,0,3,92,11};

    cout<<triangleNumber(nums);

    return 0;
    }
