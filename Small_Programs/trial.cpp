#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
int main() {
	// your code goes here
	int val1 = 10;
    int *ptr = &val1;
    int x = 1000;

    int *ptr2 = ptr;
    cout<< ptr<<' ' << ptr2<< ' '<< *ptr << ' '<< *ptr2<<endl;
    val1 = 7;
    *ptr = 400;
    cout<< ptr<<' ' << ptr2<< ' '<< *ptr << ' '<< *ptr2<<endl;




    /// pointers and arrays ///
    cout<<"\n Pointers and arrays \n ";

    int arr[5] = {1,2,3,4,5};/// remember the arr has the variables consecutive
    int *ptr_arr =arr;

	// u can deal with the arr from the pointer then
	cout<< arr[0]<< ' ' << ptr_arr[0]<<endl;
	cout<<arr<< ' ' << ptr_arr <<endl;


	cout<<"here the offset Notation ";
	cout<<*(ptr_arr+1)<<endl;

	cout<<"here the subscript Notation \n";
	cout<<ptr_arr[1];






	cout<<"here pointers arthimatic \n";

	ptr_arr++;//here i moved the pointers one st
	cout<<*++ptr_arr<<endl;//here he will increment the pointer to the next element and then print

	// here u get the value then increment the pointer
	cout<<*ptr_arr++<<endl;

	++*ptr_arr;// this get the value and then increase the value not the pointer



	int arr2[3] = {1,2,3};
	int *ptr3 = arr2+1;

    cout<<ptr3[-1]<< ' '<< ptr3[+1]<<endl;// ucan access an array like this

	return 0;
}
