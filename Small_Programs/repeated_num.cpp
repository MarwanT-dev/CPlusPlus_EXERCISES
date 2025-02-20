#include <iostream>

//the idea of the program will be next to the return 0;

using namespace std;

int main()  // any new inf will be noted with /**/
{
    int n;
    cin>>n;
    int arr[771] = {0};
    int rep_postv[271] = {0};
    int rep_neg[501] = {0};         /*this problem is imp*/




    for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>0)
                rep_postv[arr[i]]++;
            else
                rep_neg[-arr[i]]++;
        }




    int mx_pos_neg = 0;
    for(int i = 1;i<501;i++)
    {
        if(rep_neg[mx_pos_neg]<rep_neg[i])
            mx_pos_neg = i;
    }




    int mx_pos_postv = 0;
    for(int i = 1;i<271;i++)
    {
        if(rep_postv[mx_pos_postv]<rep_postv[i])
            mx_pos_postv = i;
    }



    if(rep_neg[mx_pos_neg]>rep_postv[mx_pos_postv])
        cout<<-mx_pos_neg;
    else
        cout<<mx_pos_postv;


  //7 -1 2 -1 3 -1 5 5
 //5 -10 -10 3 4 5 the program failed at this cuz u in the loop that see the greatest num in the arr u forgot and make the loop limit to (n) and the greatest repeated num was greater than n so put this in ur head that in the problms that u make another arr for notcing the repeated times make sure that u make the loop walks on it all

      return 0;//the idea of the program that the input can be a negative num so the extra idea is u make another arr for the negative one
}




