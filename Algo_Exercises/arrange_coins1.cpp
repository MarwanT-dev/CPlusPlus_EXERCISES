#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

    long long count(long long r){
        return r*(r+1)/2;
    }
    bool possible (long long r , long long n){
        if(n>=count(r))
            return 1;
        return 0;
    }
    long long BS_last_occurence(long long val,long long r){
        long long l = 0;
        long long mid = l+(r-l)/2;
        long long ans = -1;

        while(r>=l){
            if(possible(mid,val))
                ans = mid , l = mid+1;
            else
                r = mid-1;
            mid =l+(r-l)/2;
        }
        return ans;
    }

    int main(){

    long long n = 2147483647;
    cout<<BS_last_occurence(n,n-1);

    return 0;
}

