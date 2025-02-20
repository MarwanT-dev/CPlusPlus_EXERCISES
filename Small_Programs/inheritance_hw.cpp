#include <iostream>
using namespace std;

class shape{};
class two:public shape{};
class three:public shape{};
class circle:public two{};
class square:public two{};
class triangle:public two{};
class sphere:public two{};
class cube:public three{};
class terahedron:public three{};




class communityMember{};
class Employee:public communityMember{};
class student:public communityMember{};
class alumnus:public communityMember{};

class faculty:public Employee{};
class staff:public Employee{};

class administrator:public faculty{};
class teacher:public faculty{};
class administratorTeacher:public teacher,public administrator{};


class a {
    public:
    a(){
    cout<<"constructor a ";
    }
    a(string str){
    cout<<"parametrized constructor a ";
    }
};

class b {
   public:
    b(){
    cout<<"constructor b ";
    }
};

class c :public b , public a{
   public:

    c():a("ali"),b(){
    cout<<"constructor c ";
    }
};

class DecoratedString : string{

//    void decorate(){
//        this->insert("<<[[");
//        this->append(">>]]");
//    }

};

int main(){
    c C1;

return 0 ;
}

