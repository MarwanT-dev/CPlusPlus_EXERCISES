#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int count(int r){
        return r*(r+1)/2;
    }
    bool possible (int r , int n){
        if(n>=count(r))
            return 1;
        return 0;
    }
    int BS_last_occurence(int val,int r){
        int l = 0;
        int mid = l+(l-r)/2;
        int ans = -1;

        while(r>=l){
            if(possible(mid,val))
                ans = mid , l = mid+1;
            else
                r = mid-1;

        }
        return ans;
    }
    int main() {

            int n =5;
          cout<< BS_last_occurence(n,n-1);

          return 1;
    }
};
