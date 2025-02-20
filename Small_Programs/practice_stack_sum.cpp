#include <iostream >
#include <vector>
using namespace std;

int max_3stack_sum(vector<int> &v1, vector <int> &v2 , vector <int> &v3 ){
int sum1 = 0, sum2 = 0 , sum3 = 0;
    for(int i : v1)
        sum1+=i;
    for(int i : v2)
        sum2+=i;
    for(int i : v3)
        sum3+=i;
int max_sum = max(max(sum1,sum2),sum3);
int arr[] = {sum1, sum2, sum3};


bool exit = 0;
while(!exit){



    if(max_sum==sum1){
     sum1-=v1[0];
     v1.erase(v1.begin());
    }
    else if(max_sum==sum2){
        sum2-=v2[0];
        v2.erase(v2.begin());
    }
    else{
        sum3-=v3[0];
        v3.erase(v3.begin());

    }
    max_sum = max(max(sum1,sum2),sum3);

    if(sum1==max_sum&&sum2==max_sum&&sum3==max_sum)
        exit = 1;


}

return max_sum;

}

int main(){

vector <int> v1(10);vector<int>v2(10);vector<int> v3(10);
while(true){
    int s1 = 0 , s2 = 0 , s3 = 0;
    cin>>s1>>s2>>s3;
    for(int i = 0; i < s1;i++)
        cin>>v1[i];

    for(int i = 0; i < s2;i++)
        cin>>v2[i];

    for(int i = 0; i < s3;i++)
        cin>>v3[i];

    cout<<max_3stack_sum(v1,v2,v3);
}


return 0;
}
