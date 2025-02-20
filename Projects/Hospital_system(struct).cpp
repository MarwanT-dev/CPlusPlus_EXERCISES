#include <iostream>
using namespace std;
const int MAX_SPEC = 20;
const int MAX_QUEUE = 5;

struct hospital_queue{
    string names[MAX_QUEUE] ;
    int status[MAX_QUEUE]{0};
    int len,spec;

// constructors //
hospital_queue(){
        len = 0;
        spec = -1;
    }
hospital_queue(int _spec){
    len = 0;
    spec = _spec;
}



bool add_front(string name,int val){
        if(len==MAX_QUEUE)
            return false;

        //shift left
        for(int i = 0;i<len;i++){
            names[len-i] = names[len-i-1];
            status[len-i] = status[len-i-1];
        }
        names[0] = name;
        status[0] = val;
        len++;
        return true;
    }

bool add_end(string name, int val){
    if(len==MAX_QUEUE)
        return false;

    names[len] = name,status[len] = val,len++;//see if the len is increased in the case of status
    return true;
}

bool remove_front(){
    if(len==0){
        cout<<"No patients at the moment Dr. , Have rest\n";
        return false;
    }
    cout<<names[0]<<" please go with Dr.\n";
    //shift left
    string tmp_str = names[0];
    int tmp_status = status[0];
     for(int i = 0;i<len;i++){
            names[i] = names[i+1];
            status[i] = status[i+1];
        }
    len--;
    return true;
}

void print (){


    if(len==0)     return;
    cout<<"There are " <<len<<" in this specialization\n";
for(int i= 0;i<len;i++){
    cout<<names[i]<<' ';
    if(status[i])           cout<<" Urgent\n";
    else                    cout<<" Regular \n";

    }
    cout<<endl;
}
};










struct hospital_system{
hospital_queue queues[MAX_SPEC];

hospital_system(){
    for(int i = 0;i<MAX_SPEC;i++)
        queues[i] = hospital_queue(i);   //queues[i].spec = i;
    }


int menu(){
    int choice  = -1;
    while(choice==-1){
    cout<<"1) Add new patient \n";
    cout<<"2) Print all patients\n";
    cout<<"3) Get next patient\n";
    cout<<"4) Exit\n";
    cin>>choice;

    if(!(choice>=1 && choice <=4)){
        cout<<"Invalid choice. Try again\n";
        choice  = -1; // loop keep working
    }
}
    return choice ;

}
void add_patient(){
    int spec , status1;// the first status for reading status from the user
    string name;
    cout<<"Enter specialization , name ,status : " ;
    cin>>spec >> name >>status1;
    bool status2;//this for the coming status that if there are space for patients or no

        if(status1==1)
            status2 = queues[spec-1].add_front(name , status1);
        else
            status2 = queues[spec-1].add_end(name,status1);
        if(status2 ==0)
            cout<<"Sorry we can't add more patients for this specialization\n";
}

void print_patients(){
    cout<<"***************************************\n";
    for(int i = 0;i<MAX_SPEC;i++)
        queues[i].print();
}

void get_next_patient(){
    int spec ;
    cout<<"Enter specialization ";
    cin>>spec;
    queues[spec].remove_front();


}


void run (){
    while (true){
      int choice  = menu();
      if(choice ==1)
            add_patient();
      else if (choice == 2)
        print_patients();
      else if (choice ==3)
        get_next_patient();
      else
        break;
    }

   }

};



int main(){

hospital_system hospital;
hospital.run();


return 0;
}
