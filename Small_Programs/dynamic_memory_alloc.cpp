#include <iostream>
using namespace std;

int main(){
    int *p = new int;
    *p = 20;
    // by this line u made a temp location in the memory
    //then what u made u should delete it the compiler won't delete it


    int *p1 = new int {30}; //brace initialization syntax
    int *p2 = new int (40); //struct-class initialization syntax

    cout<<*p <<' '<<*p1 << ' '<< *p2;

    delete p;
    delete p1;
    delete p2;
    p = p1 = p2 =nullptr;

    /// dynamic memory alloc for arrays

    int n = 20;
    int *pArr = new int [n];

    for(int i =0;i<n;i++)
        pArr[i] = i;

    //delete pArr; this wrong and sadly it will compile

    delete[] pArr;

return 0;
}

///why we delete
 to avoid the memory leak problem that means that a part of your memory is never released till ...
When you terminate the program, all memory will be released in most of the operating systems.

So 2 things that force the memory leak to be ended:
- App close
- Machine restart

if there is a function that has big memory leak with every call it consumes
the memory until the MACHINE HANGS this means it will stop .

*COMMON MISTAKES
-use delete instead of delete[]
-use delete[] instead of delete (above one is more common)
-delete a pointer twice = DANGLING POINTER
-accessing a deleted memory
-accessing uninitialized variable

*TIPS
-never leave ptr uninitialized. at least set to nullptr
-whenever delete a pointer: assign to nullptr
-before deleting a pointer: think in the above mistakes
