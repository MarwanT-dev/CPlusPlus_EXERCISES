#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int is_zero(int val){
    return 4*pow(val,7)+3*pow(val,5)-1000;
}
int Search() {
        double  l = 0,r = 3;
        double mid = (l+r)/2;

        int cnt{};
        while(l<=r){
            if(is_zero(mid)==0){
                return mid;
            }
            else if(is_zero(mid)>0) {
                r = mid;

            }
            else
                l = mid;

            mid = (l+r)/2;
        }
        return mid;
    }

    int main(){


    cout<<Search();

    return 0;
}

