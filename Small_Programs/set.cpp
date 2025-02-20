#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
template<class a>
void print (set<a> &v){
    for(auto x : v)
        cout<<x<<' ';
    cout<<endl;

}
template<class a>
void print (multiset<a> &v){
    for(auto x : v)
        cout<<x<<' ';
    cout<<endl;

}template<class a>
void print (unordered_set<a> &v){
    for(auto x : v)
        cout<<x<<' ';
    cout<<endl;

}

int main(){
    set <string > strSet;// the set is unique and sorted
    strSet.insert("marwan");
    strSet.insert("tamer");
    strSet.insert("tamer");
    strSet.insert("tamer");
    strSet.insert("Ali");

    print(strSet);

    cout<<strSet.count("meo");//0

    if(strSet.count("Ali"))// the count function is slower than the find function below but more convenient
        cout<<" Yes " << endl;

    set<string> ::iterator it = strSet.find("marwan");
     //auto it = strSet.find("marwan");// this declaration is more convenient
    if(it != strSet.end())
        strSet.erase(it);

    print(strSet);


    /*          MultiSet             */

    multiset<string > strSet2;
    strSet2.insert("marwan");
    strSet2.insert("tamer");
    strSet2.insert("tamer");
    strSet2.insert("Ali");

    print(strSet2);

    if(strSet2.count("marwan"))
        cout<<"Yes\n";

    multiset<string > strSet3;
    strSet3.insert("marwan");
    strSet3.insert("tamer");
    strSet3.insert("tamer");
    strSet3.insert("Ali");

    print(strSet3);

    if(strSet3.count("marwan"))
        cout<<"Yes\n";

    multiset<string> ::iterator it1 = strSet3.find("tamer");
    // also we can make it auto it = strSet2.find("tamer");
    // also we can make it auto

    if(it != strSet3.end())
        strSet3.erase(it);
    print(strSet3);

    /*             Unordered Set               */

    unordered_set<int> s1{4,5,5,5,2,1,7};
    // it's unique and not ordered
    //You can't change the values when u assign it , You just insert or erase it
    // if u r forced to change val u can erase it and insert the new value
    s1.insert(10);
    s1.insert(0);

    for(auto i : s1)
        cout<<i;
    cout<<endl; //0 7 20 10 5 30 : removed duplicates

    auto it3 = s1.find(4); // FAST CUZ it's internal function in the DS so it knows how it goes from inside
    cout<<*it3<<endl;
    /// *it3 = 30 ;  //can't change

    ///generic algorithms iterate in generic/same way.
    ///    No idea about internal representation of the DS

    auto it2 = find(s1.begin(),s1.end(),7);
    cout<<*it2;

    cout<<s1.size()<<endl; //7
    s1.erase(it2);
    cout<<s1.size()<<endl; // 6




    /*       Unordered Set          */

    int arr[] = {20,10,20,40,30,7,0};
    unordered_set<int> s2(arr, arr+3);
    /// this made an unordered set with arr elements till the third elem
    ///this common way to make DS from another DS
    print(s1);
    s1.swap(s2);//this will replace the elements of them
    print(s1);

    print(s2);

    set<int> sorteds(s1.begin(),s1.end());///10 20




return 0;
}
