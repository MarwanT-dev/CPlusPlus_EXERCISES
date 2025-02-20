#include <iostream>
using namespace std;
bool EXIT = 0;

void print_e();

void print_i();

void print_alt();

void run();


int main() {

    while(!EXIT)
        run();

	return 0;
}





void run(){

    cout<<"Choose the number of the program you need: \n"
    <<"  1)the eccentricity program \n"
    <<"  2)the inclination program \n"
    <<"  3)the altitude program \n"
    <<"  4)Exit \n";

    int choice; cin>>choice;

    int times = 0;

if(choice == 1){
    cout<<"How many times you need to run the program: ";
    cin>>times;

    while(times--)
        print_e();

}

else if(choice == 2){
        cout<<"How many times you need to run the program: ";
        cin>>times;

        while(times--)
            print_i();

}

else if(choice == 3){
        cout<<"How many times you need to run the program: ";
        cin>>times;

        while(times--)
            print_alt();
}

else
    EXIT = 1;



}

void print_alt(){
    cout << "enter satellite altitude " ;
    double alt; cin >> alt;

        if (alt > 160 && alt < 2000)
            cout << "low earth's orbit \n";
        else if (alt > 5000 && alt < 10000)
            cout << "medium earth's orbit \n";
        else if (alt > 10000 && alt < 3500 )
            cout << " geostationary orbit \n";
}

void print_i(){
        cout << "enter inclination angle " ;
        double i ; cin >> i ;


        if (i == 0 )
            cout << "direct equatorial orbit \n" ;
        else if (i > 0 && i < 90 )
            cout << "direct orbit \n" ;
        else if ( i  == 90 )
            cout << "orbital period \n" ;
        else if (i  > 90 &&  i < 180 )
            cout << "indirect equatorial   orbit \n" ;
        else if ( i == 180 )
            cout << "indirect equatorial orbit \n";
}

void print_e(){
        cout << "enter eccentricty: ";
        double e ; cin >> e ;

         if (e == 0)
            cout <<"circular orbit \n";
         else if (e > 0 && e < 1)
            cout <<"elliptical orbit \n" ;
         else if (e == 1)
            cout << "parabolic orbit \n" ;
         else if (e > 1 )
            cout << "hyperbolic orbit \n" ;

}
