#include <iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int>&v){

    int min_idx = 0,min  = INT_MAX;

    for(int i = 0;i<v.size();i++){
        int min = INT_MAX;
        for(int j =i;j<v.size();j++)
            if(v[j]<min){
                min  = v[j];
                min_idx = j;
            }

        swap(v[min_idx],v[i]);
    }

}

int main(){
    vector<int>v {11,9,10};
    selection_sort(v);
    for(auto i:v)
        cout<<i<<' ';
    cout<<endl;
    v.push_back(1);
    selection_sort(v);
    for(auto i:v)
        cout<<i<<' ';
    return 0;
}
