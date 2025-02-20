#include <iostream>
using namespace std;

int max(int a,int b,int c){
    return max(a,max(b,c));
}
int max(int a ,int b,int c,int d){
    return max(a,max(b,c,d));
}
int max(int a ,int b,int c,int d,int e){
    return max(a,max(b,c,d,e));
}
int max(int a ,int b,int c,int d,int e,int f){
    return max(a,max(b,c,d,e,f));
}
/*here i made an overload for the built_in function max
so i made take more than two parameters as it overloads
(or choose ) according to the number of parameter and
that is a good inf to know that u can overload the
built_in functions
*/




int main(){

cout<<max(1,2,3,4,5,6);

}
