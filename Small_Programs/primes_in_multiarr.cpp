#include <iostream>
using namespace std;

int main() {
   bool prime[100][100] = {0};
   int n,m;
   cin>>n>>m;
   int val;
   for(int i= 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
            cin>>val;

            //here we compute the prime once NOT with every query . Also no need for MAIN ARRAY
            if(val<=1)
                continue;

            prime[i][j] = 1;
            for(int x =2;i<val;x++){//here instead of iterating to the number we can iterate to its half but make it <= to handle number 4
                if(val%x==0){
                    prime[i][j] = 0;
                    break;
                }
            }
        }

        int q;
        cin>>q;
        int si , sj , rs , cls; // this abbreviation for start i , start j , row start , cloumn start
        cin>>si >> sj >> rs >> cls;
        int cnt = 0;
        while(q--)//here we made it while loop cuz to avoid making an variable int i so we will in the other loops we will made another names we aren't used to it
        {
            for(int i =si;i<si+rs-1;i++)
                for(int j = sj;j<sj+cls-1;j++)
                    cnt+=prime[i][j];
        }



    return 0;
}

