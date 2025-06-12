#include <iostream>
#include<vector>
using namespace std;
int min_val(vector<long long>v){
    long long min = LONG_MAX;

    for(int i =0;i<v.size();i++)
        if(v[i]<min)
            min = v[i];
    return min;
}

void count_sort(vector<int>&v){
    vector<int>freq(500);


    int biggest = INT_MIN;



    for(int i =0;i<v.size();i++){
        freq[v[i]]++;
        if(v[i]>biggest)
            biggest = v[i];
    }

    v.clear();
    for(int i=0;i<biggest+1;i++){
        for(int j=0;freq[i]&&j<freq[i];j++)
           v.push_back(i);
    }


}

void count_sort_v2(vector<long long>&v){
    vector<int>freq(500);

    long long smallest = min_val(v);
    long long biggest = INT_MIN;



    for(int i =0;i<v.size();i++){
        freq[v[i]-smallest]++;
        if(v[i]>biggest)
            biggest = v[i];
    }

    v.clear();
    for(int i=0;i<biggest-smallest+1;i++){
        for(int j=0;freq[i]&&j<freq[i];j++)
           v.push_back(i+smallest);
    }


}

int main(){
    vector<long long>v {10000107,10000035,10000001,10000001,10000001};
    count_sort_v2(v);
    for(auto i:v)
        cout<<i<<' ';

    return 0;
}
