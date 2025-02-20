#include <bits/stdc++.h>
using namespace std;

void test(){
vector <int> v{3,-4,7,-2,-1,3,-5,10,3};

///let's remove the negative values
for(auto it = v.begin();it!=v.end();){
    if (*it<0){
        ///be careful when u r removing elements from DS
        ///when u remove element the function return new iterator to the next element
        ///so u shouldn't increase the iterator
        it = v.erase(it);
    }
    else
        it++; // we only increment the iterator when we don't remove elements cuz it's automatically increased when we remove element

}
for(auto &val : v)
    cout<<val<<' ';
cout<<endl;


}

void test2(){
    vector<int > v1{1,2,3,4,5,6};
    auto it  = find(v1.begin(),v1.end() , 2);

    if(it!=v1.end()){
        vector<int > v2{7,8,10};
        v1.insert(it,v2.begin(),v2.end());///note whose end and begin belongs
    }
    for(auto val : v1)
        cout<<val<<' ';
    cout<<endl;
}

int main(){
vector<int > v1;/// it's an array that can be expanded

v1.push_back(3);
v1.push_back(4);
v1.push_back(35);
v1.push_back(37);

for(int i = 0;i<(int)v1.size();i++)///it's good to cast the vector size into intger this in case u have a very big vector and also be careful when subtracting from it
    cout<< v1[i]<< ' ';
cout<<endl;

vector<int> v2(5 , 3);
///vector of length 5 and all the values = 3

v2.push_back(18);
/// see after i specified a size for it i can add elements


for(auto &val : v2)
    cout<<val<<' ';
cout<<endl;

cout<<v2.at(600);///throws an exception

///ways to avoid the idea of time and memory wasted caused from undefining the vector size and filling the internally arr then after that adding to it

vector<int> V1 (10000000);///this if u know the size of the vector u want cuz the push back is time and memory consuming

vector<int> v20;
v20.reserve(40000000);



return 0 ;
}
