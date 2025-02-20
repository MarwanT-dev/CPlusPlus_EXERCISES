#include <iostream >
#include<map>
using namespace std;

class sys;

class test {
public:
void fun(sys &s);

};
class sys {
private:
string username ;

public:
sys(const string &us):username(us){
username = us;
}
friend void test::fun(sys &a);




};

void test::fun(sys &sh){
cout<<sh.username;
}

class user{
private:
    string name , pass;

public:
    user(string name_,string pass_){
        name = name_;
        pass = pass_;
    }
    user(){

    }

};
class try_{
private:

    string str;
public:

    try_(){

    }


string change(){
    str = "we change it!";

    return str;

}

void print(){

cout<<str;}
};

int main(){
    try_ user;
    string& str_ = user.change();
    str_ = "from main";
    user.print();

return 0;
}
