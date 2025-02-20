#include<iostream>
using namespace std;

    /// some constrains

    /// another = &ref1 ; wrong will give you CE

    /// references can't be assigned to undeclared variables => int age ; int &ref = age ; WRONG

    /// and it can't be initialized to numbers (must an variable to have memory location)


    /// another = &ref1 ; wrong will give you CE



struct SpecialName {
    string name = "marwan";

    string& get_name(){     return name;    }
    void print(){       cout<<name<<endl;       }


};
string& get_message() {
    /// warning: reference to local variable
    string tmp = "hello ";
    return tmp;
}



int main(){

    SpecialName name1;
    int n = 6;
    int& x = n;
    x= 10 ;
    cout<<n<< ' '<< x;// 10 10


    /// string &nn = "malo"; CE cuz there's no variable that "malo" stored in
    ///get_message() = "marwan"; this will stop ur program here and won't continue


    string str1 = name1.get_name();// this variable isn't linked to the name1.name
    string& str2 = name1.get_name();

    str1 = "ziad";///this won't change the name in the struct

    name1.print();cout<<"this the name of the struct after str1 changed \n";

    str2 = "fawzy";/// this will change the name in the struct

    name1.print();cout<<"this the name of the struct after str2 changed \n";






    int age =55;
    int &ref1 = age ;
    int another = 30;

    ref1 = another ;



    cout<<ref1<<' ' << age << ' '<< another<<endl;
return 0;
}
