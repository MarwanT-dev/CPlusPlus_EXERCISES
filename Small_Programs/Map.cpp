#include <iostream >
#include <vector>
#include <map>


using namespace std;

void print(const map<string , int > &mp){

    for(const pair<string , int> &item : mp)
        cout<<item.first<<' ' <<item.second<<" | ";
    cout<<endl;

}
void print(const map<char , vector<int>> &mp){

    for(const pair<char , vector<int>> &item : mp){
        cout<<item.first<<' ' ;
        for(auto i : item.second)
            cout<<i<<' ';


}
    cout<<endl;

}





int main(){
    map<string,int> mp ;///it like an array but u can make the key any thing string double unlike arrays they only are integers
    mp["marwan"] = 100;
    mp["tamer"] = 200;
    mp["marwan"] = 10;///i overrided the value

    print(mp);//marwan 10 | tamer 200

    auto it = mp.find("marwa");

    if(it!=mp.end())
        mp.erase(it);

    print(mp);

    cout<<mp.count("marwan")<<endl;




    ///  MORE  ///
    map<char , vector<int> > mp1 ;
    vector < int > x= {1,2,3,4};
    mp1['A'] = x;
    x.push_back(5);

    ///this is independent vector of the one in the map
    /// so that change will not affect the map's vector

    vector<int> &y = mp1['A'];
    y.push_back(5);
    //
    print(mp1);

return 0;
}
