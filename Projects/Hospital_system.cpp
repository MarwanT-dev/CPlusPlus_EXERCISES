#include <iostream>
using namespace std;


string arr[20][5];
bool status[20][5] = {0};
int queue_length[20] = {0};




void get_next_patient(){
    int specialization;
    cout<<"Enter specialization :";
    cin>>specialization;
    specialization--;
    if(queue_length[specialization])
    {
        cout<<arr[specialization][0]<<" please go to the Dr\n";
        for(int i = 0;i<4;i++)
        {
            arr[specialization][i] = arr[specialization][i+1];
            status[specialization][i] = status[specialization][i+1];
        }
        queue_length[specialization]--;
    }
    else
        cout<<"No patients at the moment. Have rest, Dr";



}

int str_to_int(string str){
    int num = 0;
    int len = str.size();

    for(int i =0;i<len;i++)
    {
        num+=(str[i]-'0');
        if(i<len-1)
            num*=10;
    }
    return num;
}


void add_patient(string specialization ,string name,bool is_urgent){
    int int_argu1 = str_to_int(specialization)-1;

    if(queue_length[int_argu1]!=5)
    {
        if(is_urgent)
        {
            for(int i= 0;i<4;i++){//replacing method for the names and status(SHIFTING)
                arr[int_argu1][5-i-1] = arr[int_argu1][5-i-2];
                status[int_argu1][5-i-1] = status[int_argu1][5-i-2];
            }
           //assigning method
            arr[int_argu1][0] = name;
            status[int_argu1][0] = 1;

            queue_length[int_argu1]++;
        }
        else
        {
          arr[int_argu1][queue_length[int_argu1]] = name;
          status[int_argu1][queue_length[int_argu1]] = 0;
          queue_length[int_argu1] ++;
        }
    }
    else
        cout<<"Sorry we can't add more patients for this specialization\n";
}


void print(){
    for(int i = 0;i<20;i++){
        if(queue_length[i])
        {
            cout<<"************************"<<endl<<"There are "<<queue_length[i]<<" patients in specialization " <<endl;
            int len = queue_length[i];
            for(int j = 0;j<len;j++)
            {
                cout<<arr[i][j]<<' ';
                if(status[i][j])
                    cout<<"urgent\n";
                else
                    cout<<"regular\n";

            }
        }
    }
}



void hostpital_sys(int choice){
    if(choice ==1){
        string specialization , name ;
        bool status ;
        cout<<"Enter specialization , name , status: ";
        cin>>specialization>>name>>status;
        add_patient(specialization,name,status);
    }

    if(choice==2)
        print();

    if(choice ==3)
        get_next_patient();
}



int main (){

    int choice;
    bool exit = 0;


    while(!exit)
    {
        cout<<"1) Add new patient\n";
        cout<<"2) Print all patients\n";
        cout<<"3) Get next patient\n";
        cout<<"4) Exit\n";
        cin>>choice;
        if(choice ==4)exit = 1;
        hostpital_sys(choice);
    }


return 0;
}
