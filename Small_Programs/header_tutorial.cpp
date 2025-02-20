#include "header.h"



/// the idea of the header files is to make the some code in some file available to others by including it in their source code
/// as you make with the sqrt() function and the vector , etc ...


///the main file only see what in the header file can't see the implementation file
/// and the header file can't now what's happening in the imp file it only knows that its function has a declaration in that file
/// and the extra functionalities in the imp file the header file don't know about them


struct user{ // this the interface
    string name;

    user(string _name);
    void print_user();

};

///here are the imp of the interface

user::user(string _name){
    name = _name;
}

void user::print_user(){
    cout<<name;
}



int main(){

helloo();

cout<<"Even i didn't include the iostream header file the cout will work \n as it defined in the hello header file";

struct_from_header e;
e.print();
return 0;
}
