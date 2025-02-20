#include <iostream >
#include "header.h"  /// if we don't make this include this file won't be linked to the interface file
using namespace std;

int total_calls = 0;/// we can't in any .cpp file(that don't have main , if it does u can use the name) make an global var with this name





//if u made an global var here the name of it can't be used in any other .cpp files
int cannot_used_name = 10;

/// to solve this u made it static
static int can_use_name = 0100;


void helloo(){
total_calls++;
cout<<"hello from the implementation file ";
}


 struct_from_header::struct_from_header(){
 }
void struct_from_header::print(){
 cout<<"hello";
 }
/// the benefit of this file is that u can remove it and
/// make another one (you can make it with new name also)
/// but to notify the compiler that this the implementation file u need to include the header
/// this trick is being used in life facilitate the editing of the source code



