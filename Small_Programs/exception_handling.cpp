#include <iostream>
using namespace std;

int main(){
    int x{},y{};
    cin>>x>>y;
    try{

    if(x<10)
        throw invalid_argument("dd");
    if(y==0)
        throw (2);

    }
    catch(invalid_argument n){
        cout<<n.what();

    }
    catch(int n){
        cout<<"hello_1";

    }
cout<<"bye ";

return 0;
}
