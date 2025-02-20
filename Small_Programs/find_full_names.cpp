#include <iostream>
#include <vector>
#include <map>

using namespace std ;

int main(){
    int n ;
    cin>>n;
    map<string , vector<string> > mp;

for(int i = 0;i<n;i++){
    int len ;
    cin>>len;

    string cur_full_name = "";
    vector<string>names;
    string str;

    for(int j = 0;j<len;j++){
        cin>>str;

        if(j)
            cur_full_name+=" ";
        cur_full_name += str;
        names.push_back(cur_full_name);

    }

    for(auto &str: names)
        mp[str].push_back(cur_full_name);
}

int q;
cin>>q;

while(q--){
    int len ;
    cin>>len;

    string cur_full_name = "";
    string str;
    for(int j =0;j<len;j++){
        cin>>str;
        if(j)
            str+=" ";
        cur_full_name+=str;

    }
    if(mp.count(cur_full_name)){
        for(auto &name:mp[cur_full_name])
            cout<<name<<endl;
    }
    else{
        cout<<"No such sub-full name\n";
    }
}


    return 0;
}
