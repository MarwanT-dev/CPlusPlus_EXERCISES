#include <iostream>
#include<cmath>
using namespace std;

double ellipse_program(double e , double semi_minor_axis){
    return sqrt(pow(semi_minor_axis,2)/( 1-pow(e,2) ) );
}

double moon_program(int years = 1000){


}






int main() {
	bool exit = 0;
while(!exit){
    cout<<"Choose the number of the program you need: "<<endl<<"1)the ellipse program "<<endl<<"2)the moon program "<<endl<<"3)Exit \n";
    int choice; cin>>choice;

    int times{};

    if(choice == 1){

            cout<<"How many times u need to run the program: ";
            cin>>times;
            while(times--){
                cout<<"Enter the eccentricity and the semi major axis: ";

                double e , semi_minor_axis;cin>>e>>semi_minor_axis;

                cout<<endl;

                double semi_major_axis = ellipse_program(e,semi_minor_axis);

                cout<<"Semi major axis = "<<semi_major_axis<<" Km \n \n";
                cout<<"Major axis  = "<<2*semi_major_axis<<" Km \n \n";
        }

    }
    else if(choice == 2){
            cout<<"How many times u need to run the program: ";
            cin>>times;
            while(times--){
                int years = 1000;

                bool change ;

                cout<<"Enter 1 to change no. of years or 0 if you don't: ";
                cin>>change ;

                if(change){
                    cout<<"Enter the new number : ";
                    cin>>years;
                    moon_program(years);
                }

                cout<<" the distance in " << years<< " = "<< moon_program()<< " Km \n";

        }
    }
	else
        exit  = 1;
	}

	cout<<"With our sincere greetings (Eng. Gamal - Eng.Mohammed - Eng.Marwan) \n";


	return 0;
}
