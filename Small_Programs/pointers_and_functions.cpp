#include <iostream >
using namespace std;
#include <vector>
void do_math(int &x){
    x = x + 1;
    x = x * 2;
    x *= 2;

}
void do_math(int *x){
    if(x==nullptr)
        return;
    *x = *x +1;
    *x = *x * 2;
    *x *= 2;

}

void print(vector<int> *ptr){
    for(auto &n : *ptr)
        cout<< n << ' ';/// u can't deal with vectors like array arthematic

}



int* max(int *ptr1 , int *ptr2){
    if(ptr1 == nullptr) return ptr2;
    if(ptr2 == nullptr) return ptr1;

    if(*ptr1>*ptr2)
        return ptr1;
    return ptr2;

}

int main(){

int x1 = 4;

do_math(x1);

cout<<x1<< ' '<< endl;

x1 = 4;

do_math(&x1);/// this like saying in the function int *x = &x1;

cout<<x1<<' ' << endl;

vector<int> v {1,2,3,4};
print(&v);/// this like saying in the function vector<int> *x = &v;





int y = 18 , z = 100;
max(&y , &z);// this a func that compare bet numbers but by taking pointers

return 0;
}
