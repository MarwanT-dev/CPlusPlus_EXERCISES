#include <iostream>
using namespace std;


int a = 0 , b = 1 , c = 2 , d = 3;



int* returnA(){///this sample is so direct
    int *j = &a;
    return j;
}


int* returnB(){///here the pointer needs a variable adderess so u return what it want or in other words this equal to int* p = &b
    return &b;
}

int& returnC(){///remember that the reference var is an alternative name for a variable so u can return a variable
    return c;
}

int& returnC2(){/// here by returning the *d u return the variable that the pointer points to and make an alternative name for it
    int *d =&c;
    return *d;
}



int main(){
///here i will introduce the offset notation of pointers

int arr[] = {1,2,3,4,5};

int *ptr = arr;







return 0;
}
