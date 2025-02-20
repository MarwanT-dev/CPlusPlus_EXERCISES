#include <iostream>
using namespace std;
//any comment of code line means that i modified my code to mostafa's code
struct que{
int arr[200] = {0};
int len;  //int len{0};


que(){  // the default constructor (or empty constructor)
        len = 0;
    }

void shift_left(int  arr[]){
for(int i =0;i<len;i++)
    arr[i] = arr[i+1];

}
void shift_right(int  arr[]){
for(int i =0;i<len;i++)
    arr[len-i] = arr[len-i-1];

}

void add_end(int val){
    arr[len++] = val; // don't worry of the ++ it will increment val after assigning then it will be increased
}

void add_front(int val){
    shift_right(arr);
    arr[0] = val;
    len++;
}

int remove_front(){
    int tmp = arr[0];
    len--;
    shift_left(arr);
    return tmp;
}

void print_arr(){
for(int i = 0 ;i<len;i++)
    cout<<arr[i]<<' ';
    cout<<endl;
}


};



int main(){
que my_queue;
my_queue.add_front(20);
my_queue.add_front(2);
my_queue.add_end(100);
my_queue.print_arr();

my_queue.add_front(1);
my_queue.add_front(4);
my_queue.print_arr();
cout<<my_queue.remove_front()<<endl;
my_queue.print_arr();

return 0;
}
