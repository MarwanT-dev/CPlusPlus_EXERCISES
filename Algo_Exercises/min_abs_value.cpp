#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> insertion_sort_v1(vector<int> &arr){

    sort(arr.begin(),arr.end());
    vector<vector<int>>freq;

    int min {0};
    for(int i =0;i<arr.size()-1;i++){
            int cur_diff = arr[i+1]-arr[i];
            if(i==0)
                min =cur_diff;

            if(cur_diff<min)
                min = cur_diff,freq.clear();

            if(cur_diff==min)
                freq.push_back({arr[i],arr[i+1]});




    }

    return freq;
}


int main()
{
    vector<int>v {4,2,1,3};
    vector<vector<int>> result = insertion_sort_v1(v);
    for(auto j :result)
        for(auto i:j)
            cout<<i<<' ';

    return 0;
}
