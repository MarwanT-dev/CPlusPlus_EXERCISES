#include <iostream>
#include<sstream>
using namespace std;

void read(int &a,int &b);
void read2(int &a,int &b);
int main(){

    int age;
    cout<<"Enter your age: ";
    cin>>age;

    cin.ignore(256,'\n');

    string full_name;
    cout<<"Enter full name: ";
    getline(cin,full_name);

    //here the getline won't read the name it will take the /n u entered
    //by pressing enter , so to avoid that we use cin.ignore()




    cout<<age <<' '<< full_name<<endl;




    /* type check */

    int a , b;
    //read(a,b);
    read2(a,b);

return 0;
}

void read(int &a , int &b){
    while(true){
            cin>>a>>b;

        if(cin.fail()){
            cout<<"something wroing in input. Try again: ";
            cin.clear();//it clears the problem that happen in the cin and makes it ready to read again
            cin.ignore(256,'\n');//here to ignore the rest of the input
        }
        else
            break;
    }
}
void read2(int &a , int &b){

    string line;

    while(true){
        getline(cin,line);


        istringstream iss(line);
        iss>>a>>b;

        if(iss.fail()){
            cout<<"something wroing in input. Try again: ";
            cin.clear();//it clears the problem that happen in the cin and makes it ready to read again
            //cin.ignore(256,'\n');//here to ignore the rest of the input
        }
        else
            break;
    }
}
