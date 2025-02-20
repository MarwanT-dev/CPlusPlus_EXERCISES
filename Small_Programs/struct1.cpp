#include <iostream>
using namespace std;

struct emplyee{
    string name;
    int age ;
    double salary;
    char gender ;
};



emplyee arr[1000]{};//here the all the four aspects will be assigned relative to the defult constructor for the data type int => 0 string/char => ""/''
int added;//this will be assigned to zero as it's a global var

bool compare_name (emplyee &a , emplyee &b){
    return (a.name>b.name);
}
bool compare_salary(emplyee &a , emplyee &b){
    return (a.salary>b.salary);
}
bool compare_name_salary(emplyee &a , emplyee &b){
    if(a.name!=b.name)
        return a.name>b.name;
    return a.salary>b.salary;
}
void read_employee_v1(){
    cout<<"Enter employee 4 entries: ";
    cin>>arr[added].name >>arr[added].age;
    cin>>arr[added].salary>> arr[added].gender;
    added++;
}
void print_employee_v1(){
    for(int i =0;i<added ;i++)
    {
        emplyee e = arr[i];
        cout<<e.name<<" has salary "<<e.salary<<endl;
    }
}

void read_employee_v2(emplyee &e){//NOTICE here we must put the reference & cuz otherwise it the data will not be assigned to the array as e is just a copy
    cout<<"Enter employee 4 entries: ";
    cin>>e.name >>e.age;
    cin>>e.salary>> e.gender;
}
void print_employee(emplyee & e){//NOTICE here we put the reference just for saving time and memory that is consumed when we remove it as it will make copies
    cout<<e.name<<"has salary "<<e.salary;
}
void print_employees_v2(){
    for(int i =0;i<added;i++)
        print_employee(arr[added]);
}


int main(){
//making variables with struct
    emplyee first = {"marwan",14,14000,'M'};


//reading and printing

read_employee_v1();
print_employee_v1();



read_employee_v2(arr[added++])/*NOTICE here the postfix ++ so it will assign the old value and then increase it after calling
this way we get rid of that we increment inside the function as in v1
*/
print_employees_v2()
return 0;
}
