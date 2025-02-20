#include <iostream >
using namespace std;



int main (){

int val = 10;
int *ptr = &val;
*ptr = 200;

cout<<val << ' '<< *ptr << endl; //200 200

cout<<ptr << ' ' << &ptr << ' '<< *ptr<<endl ; // the address of the value that the ptr points to, the address of the pointer in the memory , the value the ptr points to

/// the * is known as the dereference , its Role : indirect addressing ,

int x = 40;
*ptr = x;
x = 50;///this won't change ptr and val cuz the ptr is pointing to val

cout<<*ptr << ' '<< val << ' ' << x<<endl;

ptr = &x;///by this step ptr is pointing to x

cout<<*ptr << ' '<< val << ' ' << x<<endl;

ptr = &val ;


/// tihs pointer points to nothing  , u can't make that with references
///these are all ways to define null pointer

int *ptr1 = nullptr;
int *ptr2 = NULL;
int *ptr3 = 0;


/// cout<<*ptr1; this an run time error , cuz it doesn't point to nothing


/// int *ptr = 1; u can't assign ptr to non variable

int *ptr4 ; /// Garbage - DON'T Make this

if(!ptr1)
    cout<<"NULL POINTER\n";
// NULL POINTER
return 0;
}
