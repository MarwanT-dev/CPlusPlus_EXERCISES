#include <iostream>
#include <vector>
using namespace std;

struct employee{
    int id = -1;
    string name;

    employee(){

    }
    employee(int id_, string name_){
        id = id_;
        name = name_;
    }

    void print(){
        cout<<id<<' ' << name<<endl;
    }

};

int main(){
    employee e1{10 , "marwan"};
    e1.print();

    /// int* x = new int(100); or int* x { new int(50) }
    employee* e2 { new employee(20 , "belal")};

    e2->print();

    /// or u can make this method but it's less common

    (*e2).print();// u call the variable inside the pointer and then used the .

    employee* e3 = e2;
    employee* e4 = &e1;

    e3->name = "marwan";
    cout<<e2->name<<' ' << e3->name;

    employee& e5 = *e4;// u made an allias for *e4 so if u changed the pointer e5 will also change

    vector<employee*> v;
    v.push_back(e2);
    v.push_back(&e1);// i put here &e1 cuz it takes pointer which store inside it address of a memory location

    delete e2; // if u don't delete it , it will make memory leak

    e2 = nullptr; // to safely delete the pointer
return 0;
}
