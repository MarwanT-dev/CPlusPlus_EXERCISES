#include<iostream>
using namespace std;

bool is_prime(int x){
    bool prime = 1;
    for(int i = 2;i<x;i++)
    {
        if(x%i==0)
        {
            prime = 0;
            return 0;
        }
    }
    return 1;
}
int nth_prime(int n){
    int primes = 0;
    int wanted_prime = 0;
    for(int i =1;n!=primes;i++)
    {
        if(is_prime(i))
        {
            primes++;
            wanted_prime = i;
        }

    }
    return wanted_prime;
}

int main(){

    int n;
    cin>>n;
    cout<<nth_prime(n);



return 0;
}
