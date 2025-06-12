#include <iostream>
#include<vector>
using namespace std;
void insertion_sort_v1(vector<int> &v){
    for(int i =1;i<v.size();i++){
        int temp = v[i];
        int j = i;
        while(j>=1&&temp<v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
}

void insertion_sort_v2(vector<int> &v){
    for(int i =1;i<v.size();i++){
        for(int j = i;j>=1&&v[j]<v[j-1];j--)
            swap(v[j],v[j-1]);
    }
}

int main()
{
    vector<int>v {8,2,1};
    insertion_sort_v2(v);
    for(auto i:v)
        cout<<i<<' ';

    return 0;
}
